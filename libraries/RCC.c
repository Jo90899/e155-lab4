// STM32L432KC_RCC.c
// Source code for RCC functions

#include "RCC.h"

void configurePLL() {
    // Set clock to 80 MHz
    // Output freq = (src_clk) * (N/M) / R
    // (4 MHz) * (N/M) / R = 80 MHz
    // M: 1, N: 80, R: 4
    // Use MSI as PLLSRC

    //Turn off PLL
    RCC->CR &= ~(1<<24); // PLLON set to 0

    //Wait till PLL is unlocked (e.g., off)
    while ((RCC->CR >> 25 & 1) != 0); // waits, then PLLRDY set to 0

    // Load configuration
    //Set PLL SRC to MSI
    RCC->PLLCFGR &= ~(0b11<<0); // PLLSRC bits cleared
    RCC->PLLCFGR |= (0b01<<0); // PLLSRC bits set to 01, SRC=MSI

    //Set PLLN
    RCC->PLLCFGR &= ~(0b1111111<<8); // PLLN bits cleared
    RCC->PLLCFGR |= (0b1010000<<8); // PLLN bits set to 80

    //Set PLLM
    RCC->PLLCFGR &= ~(0b111<<4); // PLLM bits cleared
    RCC->PLLCFGR |= (0b000<<4); // PLLM bits set to 000, M=1
    
    //Set PLLR
    RCC->PLLCFGR &= ~(0b11<<25); // PLLR bits cleared
    RCC->PLLCFGR |= (0b01<<25); // PLLR bits set to 01, R=4
    
    //Enable PLLR output
    RCC->PLLCFGR |= (1<<24); // PLLREN bit set to 1
    
    //Enable PLL
    RCC->CR |= (1<<24); // PLLON set to 1
    
    //Wait until PLL is locked
    while ((RCC->CR >> 25 & 1) != 1); // PLLRDY set to 0
    
}

void configureClock(){
    // Configure and turn on PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR |= (0b11 << 0);
    while(!((RCC->CFGR >> 2) & 0b11));
}