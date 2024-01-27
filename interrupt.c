/*
 * File: interrupt.c
 * Author: phamtien758
 * 
 */

/*** INCLUDE ************************************/
#include "interrupt.h"

/*** PROTOTYPE **********************************/

/*** VARIABLE ***********************************/
static Function_Handler p_FuncHandler[MAX_PEPRI_IRQ_NUM] = {NULL};

/*** STATIC FUNCTION ****************************/

/*** FUNCTIONS **********************************/
void Nvic_SetHandlerFunc(Irq_Number IrqNum_e, Function_Handler p_HandlerFunc)
{
    p_FuncHandler[IrqNum_e] = p_HandlerFunc;
}

void Nvic_EnableIrq(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_ISER;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_ISER;

    NVIC->ISER[RegIndex_u32] |= NVIC_ISER_IRQ_MASK(BitIndex_u32);
}

void Nvic_DisableIrq(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_ICER;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_ICER;

    NVIC->ICER[RegIndex_u32] |= NVIC_ICER_IRQ_MASK(BitIndex_u32);
}

void Nvic_SetPendingIrq(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_ISPR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_ISPR;

    NVIC->ISPR[RegIndex_u32] |= NVIC_ISPR_IRQ_MASK(BitIndex_u32);
}

void Nvic_ClearPendingIrq(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_ICPR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_ICPR;

    NVIC->ICPR[RegIndex_u32] |= NVIC_ICPR_IRQ_MASK(BitIndex_u32);
}

uint8_t Nvic_IsPendingIrq(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;
    uint8_t RetValue_u8;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_ICPR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_ICPR;

    if(0U != (NVIC->ICPR[RegIndex_u32] & NVIC_ICPR_IRQ_MASK(BitIndex_u32)))
    {
        RetValue_u8 = (uint8_t)TRUE;
    }
    else
    {
        RetValue_u8 = (uint8_t)FALSE;
    }

    return RetValue_u8;
}

void Nvic_SetPriority(Irq_Number IrqNum_e, Irq_Pri PriNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_IPR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_IPR;
    
    NVIC->IPR[RegIndex_u32] |= (PriNum_e << NVIC_IPR_IRQ_POS(BitIndex_u32));
}

uint8_t Nvic_GetPriority(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;
    uint8_t RetValue_u8;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_IPR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_IPR;
    
    RetValue_u8 = (uint8_t)((NVIC->IPR[RegIndex_u32] & \
                            NVIC_IPR_IRQ_MASK(BitIndex_u32)) >> \
                            NVIC_IPR_IRQ_POS(BitIndex_u32));

    return RetValue_u8;
}

uint8_t Nvic_IsActive(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;
    uint8_t RetValue_u8;

    RegIndex_u32 = (uint32_t)IrqNum_e / (uint32_t)NUM_IRQ_PER_NVIC_IABR;
    BitIndex_u32 = (uint32_t)IrqNum_e % (uint32_t)NUM_IRQ_PER_NVIC_IABR;

    if(0U != (NVIC->ICPR[RegIndex_u32] & NVIC_IABR_IRQ_MASK(BitIndex_u32)))
    {
        RetValue_u8 = (uint8_t)TRUE;
    }
    else
    {
        RetValue_u8 = (uint8_t)FALSE;
    }

    return RetValue_u8;
}

// /* Handler functions re-definition */
// void EXTI16_PVD_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_EXTI16])();
// }

// void TAMP_STAMP_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_EXTI21])();
// }

// void EXTI22_RTC_WKUP_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_EXTI22])();
// }

// void FLASH_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_FLASH])();
// }

// void RCC_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_RCC])();
// }

// void DMA1_Stream0_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_0])();
// }

// void DMA1_Stream1_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_1])();
// }

// void DMA1_Stream2_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_2])();
// }

// void DMA1_Stream3_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_3])();
// }

// void DMA1_Stream4_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_4])();
// }

// void DMA1_Stream5_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_5])();
// }

// void DMA1_Stream6_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_6])();
// }

// void ADC_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_ADC])();
// }

// void TIM1_BRK_TIM9_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM1_BRK_TIM9])();
// }

// void TIM1_UP_TIM10_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM1_UP_TIM10])();
// }

// void TIM1_TRG_COM_TIM11_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM1_TRG_COM_TIM11])();
// }

// void TIM1_CC_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM1_CC])();
// }

// void TIM2_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM2])();
// }

// void TIM3_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM3])();
// }

// void TIM4_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM4])();
// }

// void I2C1_EV_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C1_EV])();
// }

// void I2C1_ER_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C1_ER])();
// }

// void I2C2_EV_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C2_EV])();
// }

// void I2C2_ER_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C2_ER])();
// }

// void SPI1_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_SPI1])();
// }

// void SPI2_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_SPI2])();
// }

// void USART1_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_USART1])();
// }

// void USART2_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_USART2])();
// }

// void EXTI17_RTC_Alarm_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_EXTI17])();
// }

// void EXTI18_OTG_FS_WKUP_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_EXTI18])();
// }

// void DMA1_Stream7_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA1_7])();
// }

// void SDIO_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_SDIO])();
// }

// void TIM5_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_TIM5])();
// }

// void SPI3_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_SPI3])();
// }

// void DMA2_Stream0_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_0])();
// }

// void DMA2_Stream1_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_1])();
// }

// void DMA2_Stream2_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_2])();
// }

// void DMA2_Stream3_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_3])();
// }

// void DMA2_Stream4_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_4])();
// }

// void OTG_FS_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_OTG_FS])();
// }

// void DMA2_Stream5_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_5])();
// }

// void DMA2_Stream6_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_6])();
// }

// void DMA2_Stream7_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_DMA2_7])();
// }

// void USART6_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_USART6])();
// }

// void I2C3_EV_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C3_EV])();
// }

// void I2C3_ER_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_I2C3_ER])();
// }

// void SPI4_IRQHandler(void)
// {
//     (p_FuncHandler[IRQ_NUM_SPI4])();
// }