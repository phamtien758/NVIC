/*******************************************************************************
 * File  : interrupt.c       
 * Author: phamtien758      
 * Brief : Interrupt source file
 ******************************************************************************/

/*** INCLUDE ************************************/

#include "interrupt.h"

/*** PROTOTYPE **********************************/

/*** VARIABLE ***********************************/

/*** STATIC FUNCTION ****************************/

/*** FUNCTIONS **********************************/

/**
  * @brief   Enable interrupt
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  None
  */
void Nvic_EnableIrq(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_ISER;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_ISER;

    NVIC->ISER[RegIndex_u32] |= NVIC_ISER_IRQ_MASK(BitIndex_u32);
}

/**
  * @brief   Enable interrupt
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  None
  */
void Nvic_DisableIrq(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_ICER;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_ICER;

    NVIC->ICER[RegIndex_u32] |= NVIC_ICER_IRQ_MASK(BitIndex_u32);
}

/**
  * @brief   Set interrupt to pending state
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  None
  */
void Nvic_SetPendingIrq(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_ISPR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_ISPR;

    NVIC->ISPR[RegIndex_u32] |= NVIC_ISPR_IRQ_MASK(BitIndex_u32);
}

/**
  * @brief   Clear pending state of interrupt
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  None
  */
void Nvic_ClearPendingIrq(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_ICPR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_ICPR;

    NVIC->ICPR[RegIndex_u32] |= NVIC_ICPR_IRQ_MASK(BitIndex_u32);
}

/**
  * @brief   Check if IRQ is pending state or not
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  TRUE - IRQ is pending state
  *          FALSE - IRQ isn't pending state
  */
uint8 Nvic_IsPendingIrq(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;
    uint8 RetValue_u8;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_ICPR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_ICPR;

    if(0U != (NVIC->ICPR[RegIndex_u32] & NVIC_ICPR_IRQ_MASK(BitIndex_u32)))
    {
        RetValue_u8 = (uint8)TRUE;
    }
    else
    {
        RetValue_u8 = (uint8)FALSE;
    }

    return RetValue_u8;
}

/**
  * @brief   Set priority of interrupt
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @param   PriNum_e   Priority value.
  * @retval  None
  */
void Nvic_SetPriority(Irq_Number IrqNum_e, Irq_Pri PriNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_IPR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_IPR;
    
    NVIC->IPR[RegIndex_u32] |= (PriNum_e << NVIC_IPR_IRQ_POS(BitIndex_u32));
}

/**
  * @brief   Return priority value of an interrupt
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  uint8 - Priority value
  */
uint8 Nvic_GetPriority(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;
    uint8 RetValue_u8;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_IPR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_IPR;
    
    RetValue_u8 = (uint8)((NVIC->IPR[RegIndex_u32] & \
                            NVIC_IPR_IRQ_MASK(BitIndex_u32)) >> \
                            NVIC_IPR_IRQ_POS(BitIndex_u32));

    return RetValue_u8;
}

/**
  * @brief   Check if IRQ is active or not
  * @note    None
  * @param   IrqNum_e   IRQ number.
  * @retval  uint8 - Priority value
  */
uint8 Nvic_IsActive(Irq_Number IrqNum_e)
{
    uint32 RegIndex_u32;
    uint32 BitIndex_u32;
    uint8 RetValue_u8;

    RegIndex_u32 = (uint32)IrqNum_e / (uint32)NUM_IRQ_PER_NVIC_IABR;
    BitIndex_u32 = (uint32)IrqNum_e % (uint32)NUM_IRQ_PER_NVIC_IABR;

    if(0U != (NVIC->ICPR[RegIndex_u32] & NVIC_IABR_IRQ_MASK(BitIndex_u32)))
    {
        RetValue_u8 = (uint8)TRUE;
    }
    else
    {
        RetValue_u8 = (uint8)FALSE;
    }

    return RetValue_u8;
}