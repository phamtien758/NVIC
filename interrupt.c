/*
 * File: interrupt.c
 * Author: phamtien758
 * 
 */

/*** INCLUDE ************************************/
#include "interrupt.h"

/*** PROTOTYPE **********************************/

/*** VARIABLE ***********************************/

/*** STATIC FUNCTION ****************************/

/*** FUNCTIONS **********************************/
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

uint32_t Nvic_GetActive(Irq_Number IrqNum_e)
{
    uint32_t RegIndex_u32;
    uint32_t BitIndex_u32;
    uint8_t RetValue_u8;
    uint8_t Loop_u8;

    for(Loop_u8 = 0, Loop_u8 < 8U, Loop_u8++)
    {
        if(0 != (NVIC->IABR[Loop_u8] & 0xFFFFFFFF))
    }

    return RetValue_u8;
}