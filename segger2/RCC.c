// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// RCC.c file with clock and PLL configuration functions

#include "RCC.h"

void configurePLL() {
    RCC->CR &= ~(1<<24);     //Turn off PLL

    while ((RCC->CR >> 25 & 1) != 0); //Wait till PLL is off, then set PLLRDY to 0

    // Set to MSI clock
    RCC->PLLCFGR &= ~(0b11<<0); 
    RCC->PLLCFGR |= (0b01<<0); 

    //Set PLLN
    RCC->PLLCFGR &= ~(0b1111111<<8); 
    RCC->PLLCFGR |= (0b1010000<<8);

    //Set PLLM
    RCC->PLLCFGR &= ~(0b111<<4);
    RCC->PLLCFGR |= (0b000<<4); 
    
    //Set PLLR
    RCC->PLLCFGR &= ~(0b11<<25); 
    RCC->PLLCFGR |= (0b01<<25);
    
    //Set PLLR output enable
    RCC->PLLCFGR |= (1<<24); 
    
    //Enable PLL
    RCC->CR |= (1<<24);
    
    while ((RCC->CR >> 25 & 1) != 1); // Wait until PLL is ready, then set PLLRDY to 0
    
}

void configureClock(){
    // Configure PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR |= (0b11 << 0);
    while(!((RCC->CFGR >> 2) & 0b11));
}