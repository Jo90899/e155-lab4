// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// TIMER.c file with TIM configuration and frequency/delat setup

#include "TIMER.h"

#define CK_CNT 80000000

void configureTIM(TIMxx_TypeDef *TIMx){
    //Set CCMR1 to PWM
    TIMx->CCMR1 &= ~(0b111<<4); 
    TIMx->CCMR1 |= (0b110<<4); 

    //Set CCMR1 preload enable
    TIMx->CCMR1 |= (1<<3); 

    //Set CR1
    TIMx->CR1 |= (1<<7); 
    TIMx->PSC &= ~(65535<<0); 
    TIMx->PSC |= (1023<<0); 
    TIMx->CCER |= (1<<0); 
    TIMx->BDTR |= (1<<15); 

    //Enable UG
    TIMx->EGR |= (1<<0); 
    TIMx->CR1 |= (1<<0); 
};

void setFreq(int freq, TIMxx_TypeDef *TIMx){
    // Determine frequency
    if (freq==0) {
        TIMx->ARR &= ~(65535<<0); 
        TIMx->CR1 &= ~(1<<0); 
    }
    else {
        int newARR = (CK_CNT/(1024)/freq); 
        TIMx->ARR &= ~(65535<<0); 
        TIMx->ARR |= (newARR<<0); 
        int dutycycle = newARR/2;
        TIMx->CCR1 &= ~(65535<<0); 
        TIMx->CCR1 |= (dutycycle<<0); 
        TIMx->EGR |= (1<<0); 
        TIMx->CR1 |= (1<<0); 
    }
};

void setDur(int dur, TIMxx_TypeDef *TIMx){
    int ticks = CK_CNT/(1024)/1000*dur; // in milliseconds
    TIMx->ARR = ticks; 
    TIMx->EGR |= (1<<0); 
    TIMx->SR &= ~(1<<0); // Overflow flag
    TIMx->CNT = 0; 
    
    while (!(TIMx->SR & (1<<0))); 
};