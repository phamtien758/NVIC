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

/*** PROTOTYPE ************************************/
void Nvic_EnableIrq(Irq_Number IrqNum_e);
void Nvic_DisableIrq(Irq_Number IrqNum_e);
void Nvic_SetPendingIrq(Irq_Number IrqNum_e);
void Nvic_ClearPendingIrq(Irq_Number IrqNum_e);
void Nvic_GetPendingIrq(Irq_Number IrqNum_e);
void Nvic_SetPriority(Irq_Number IrqNum_e, Irq_Pri PriNum_e);
uint8_t Nvic_GetPriority(Irq_Number IrqNum_e);
uint32_t Nvic_GetActive(Irq_Number IrqNum_e);

#endif /* INTERRUPT_H */