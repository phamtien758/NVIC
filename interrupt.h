/*
 * File: interrupt.h
 * Author: phamtien758
 * 
 */

#ifndef INTERRUPT_H
#define INTERRUPT_H

/*** INCLUDE ************************************/
#include "stm32f401re.h"

/*** DEFINE *************************************/
#define NUM_IRQ_PER_NVIC_ISER    ((uint32_t)(NVIC_ISER_REG_WIDTH / \
                                             NVIC_ISER_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ICER    ((uint32_t)(NVIC_ICER_REG_WIDTH / \
                                             NVIC_ICER_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ISPR    ((uint32_t)(NVIC_ISPR_REG_WIDTH / \
                                             NVIC_ISPR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ICPR    ((uint32_t)(NVIC_ICPR_REG_WIDTH / \
                                             NVIC_ICPR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_IABR    ((uint32_t)(NVIC_IABR_REG_WIDTH / \
                                             NVIC_IABR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_IPR    ((uint32_t)(NVIC_IPR_REG_WIDTH / \
                                             NVIC_IPR_BIT_PER_IRQ))

/*** TYPEDEF ************************************/
/*
 * @Function_Handler
 *
 */
typedef void (*Function_Handler)(void);

/*** PROTOTYPE ************************************/
void Nvic_EnableIrq(Irq_Number IrqNum_e);
void Nvic_DisableIrq(Irq_Number IrqNum_e);
void Nvic_SetPendingIrq(Irq_Number IrqNum_e);
void Nvic_ClearPendingIrq(Irq_Number IrqNum_e);
void Nvic_GetPendingIrq(Irq_Number IrqNum_e);
void Nvic_SetPriority(Irq_Number IrqNum_e, Irq_Pri PriNum_e);
uint8_t Nvic_GetPriority(Irq_Number IrqNum_e);
uint32_t Nvic_GetActive(Irq_Number IrqNum_e);

/* Prototypes for interrupt handlers re-definition */
void EXTI16_PVD_IRQHandler(void);
void TAMP_STAMP_IRQHandler(void);
void EXTI22_RTC_WKUP_IRQHandler(void);
void FLASH_IRQHandler(void);
void RCC_IRQHandler(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler9(void);
void DMA1_Stream0_IRQHandler(void);
void DMA1_Stream1_IRQHandler(void);
void DMA1_Stream2_IRQHandler(void);
void DMA1_Stream3_IRQHandler(void);
void DMA1_Stream4_IRQHandler(void);
void DMA1_Stream5_IRQHandler(void);
void DMA1_Stream6_IRQHandler(void);
void ADC_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM1_TRG_COM_TIM11_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void I2C2_EV_IRQHandler(void);
void I2C2_ER_IRQHandler(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void EXTI17_RTC_Alarm_IRQHandler(void);
void EXTI18_OTG_FS_WKUP_IRQHandler(void);
void DMA1_Stream7_IRQHandler(void);
void SDIO_IRQHandler(void);
void TIM5_IRQHandler(void);
void SPI3_IRQHandler(void);
void DMA2_Stream0_IRQHandler(void);
void DMA2_Stream1_IRQHandler(void);
void DMA2_Stream2_IRQHandler(void);
void DMA2_Stream3_IRQHandler(void);
void DMA2_Stream4_IRQHandler(void);
void OTG_FS_IRQHandler(void);
void DMA2_Stream5_IRQHandler(void);
void DMA2_Stream6_IRQHandler(void);
void DMA2_Stream7_IRQHandler(void);
void USART6_IRQHandler(void);
void I2C3_EV_IRQHandler(void);
void I2C3_ER_IRQHandler(void);
void SPI4_IRQHandler(void);

#endif /* INTERRUPT_H */