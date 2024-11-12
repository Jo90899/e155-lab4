// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// TIMER.h header file with TIM struct

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

#define TIM15_BASE (0x40014000) //TIM15 Base Address
#define TIM16_BASE (0x40014400) //TIM16 Base Address

typedef struct{
    volatile uint32_t CR1;          // 0x00: CR1
    volatile uint32_t CR2;          // 0x04: CR2
    volatile uint32_t RESERVED0;
    volatile uint32_t DIER;         // 0x0C: DIER
    volatile uint32_t SR;           // 0x10: SR
    volatile uint32_t EGR;          // 0x14: EGR
    volatile uint32_t CCMR1;        // 0x18: CCMR1
    volatile uint32_t RESERVED1;  
    volatile uint32_t CCER;         // 0x20: CCER
    volatile uint32_t CNT;          // 0x24: CNT
    volatile uint32_t PSC;          // 0x28: PSC
    volatile uint32_t ARR;          // 0x2C: ARR
    volatile uint32_t RCR;          // 0x30: RCR
    volatile uint32_t CCR1;         // 0x34: CCR1
    volatile uint32_t RESERVED2 [3];
    volatile uint32_t BDTR;         // 0x44: BDTR
    volatile uint32_t DCR;          // 0x48: DCR
    volatile uint32_t DMAR;         // 0x4C: DMAR
    volatile uint32_t OR1;          // 0x50: OR1
    volatile uint32_t RESERVED3 [3];
    volatile uint32_t OR2;          // 0x60: OR2
} TIMxx_TypeDef;

#define TIM15 ((TIMxx_TypeDef *) TIM15_BASE)
#define TIM16 ((TIMxx_TypeDef *) TIM16_BASE)

void configureTIM(TIMxx_TypeDef *TIMx);
void setFreq(int freq, TIMxx_TypeDef *TIMx);
void setDur(int dur, TIMxx_TypeDef *TIMx);

#endif