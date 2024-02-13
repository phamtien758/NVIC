/*******************************************************************************
 * File  : interrupt.h       
 * Author: phamtien758      
 * Brief : Interrupt header file
 ******************************************************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H

/*** INCLUDE ************************************/

#include "stm32f401re.h"

/*** DEFINE *************************************/

/* Number of IRQ in these register (register bit width / IRQ bit width) */
#define NUM_IRQ_PER_NVIC_ISER    ((uint32)(NVIC_ISER_REG_WIDTH / \
                                             NVIC_ISER_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ICER    ((uint32)(NVIC_ICER_REG_WIDTH / \
                                             NVIC_ICER_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ISPR    ((uint32)(NVIC_ISPR_REG_WIDTH / \
                                             NVIC_ISPR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_ICPR    ((uint32)(NVIC_ICPR_REG_WIDTH / \
                                             NVIC_ICPR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_IABR    ((uint32)(NVIC_IABR_REG_WIDTH / \
                                             NVIC_IABR_BIT_PER_IRQ))

#define NUM_IRQ_PER_NVIC_IPR    ((uint32)(NVIC_IPR_REG_WIDTH / \
                                             NVIC_IPR_BIT_PER_IRQ))

/*** TYPEDEF ************************************/

/*** PROTOTYPE ************************************/

/* Enable interrupt */
void Nvic_EnableIrq(Irq_Number IrqNum_e);

/* Disable interrupt */
void Nvic_DisableIrq(Irq_Number IrqNum_e);

/* Disable interrupt */
void Nvic_SetPendingIrq(Irq_Number IrqNum_e);

/* Clear pending state of interrupt */
void Nvic_ClearPendingIrq(Irq_Number IrqNum_e);

/* Check if an interrupt is pending or not */
uint8 Nvic_IsPendingIrq(Irq_Number IrqNum_e);

/* Set priority of interrupt */
void Nvic_SetPriority(Irq_Number IrqNum_e, Irq_Pri PriNum_e);

/* Get priority value of interrupt */
uint8 Nvic_GetPriority(Irq_Number IrqNum_e);

/* Check if an interrupt is pending or not */
uint8 Nvic_IsActive(Irq_Number IrqNum_e);

#endif /* INTERRUPT_H */