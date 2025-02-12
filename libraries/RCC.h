// STM32L432KC_RCC.h
// Header for RCC functions

#ifndef STM32L4_RCC_H
#define STM32L4_RCC_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Base addresses
#define RCC_BASE (0x40021000UL) // base address of RCC

// PLL
#define PLLSRC_HSI 0
#define PLLSRC_HSE 1

// Clock configuration
#define SW_HSI  0
#define SW_HSE  1
#define SW_PLL  2

typedef struct 
{
    volatile uint32_t CR;            // 0x00: Clock control register
    volatile uint32_t ICSCR;         // 0x04: Internal clock sources calibration register
    volatile uint32_t CFGR;          // 0x08: Clock configuration register
    volatile uint32_t PLLCFGR;       // 0x0C: PLL configuration register
    volatile uint32_t PLLSAI1CFGR;   // 0x10: PLLSAI1 configuration register
             uint32_t RESERVED0;     // 0x14: Reserved
    volatile uint32_t CIER;          // 0x18: Clock interrupt enable register
    volatile uint32_t CIFR;          // 0x1C: Clock interrupt flag register
    volatile uint32_t CICR;          // 0x20: Clock interrupt clear register
             uint32_t RESERVED1;     // 0x24: Reserved
    volatile uint32_t AHB1RSTR;      // 0x28: AHB1 peripheral reset register
    volatile uint32_t AHB2RSTR;      // 0x2C: AHB2 peripheral reset register
    volatile uint32_t AHB3RSTR;      // 0x30: AHB3 peripheral reset register
             uint32_t RESERVED2;     // 0x34: Reserved
    volatile uint32_t APB1RSTR1;     // 0x38: APB1 peripheral reset register 1
    volatile uint32_t APB1RSTR2;     // 0x3C: APB1 peripheral reset register 2
    volatile uint32_t APB2RSTR;      // 0x40: APB2 peripheral reset register
             uint32_t RESERVED3;     // 0x44: Reserved
    volatile uint32_t AHB1ENR;       // 0x48: AHB1 peripheral clock enable register
    volatile uint32_t AHB2ENR;       // 0x4C: AHB2 peripheral clock enable register
    volatile uint32_t AHB3ENR;       // 0x50: AHB3 peripheral clock enable register
             uint32_t RESERVED4;     // 0x54: Reserved
    volatile uint32_t APB1ENR1;      // 0x58: APB1 peripheral clock enable register 1
    volatile uint32_t APB1ENR2;      // 0x5C: APB1 peripheral clock enable register 2
    volatile uint32_t APB2ENR;       // 0x60: APB2 peripheral clock enable register
             uint32_t RESERVED5;     // 0x64: Reserved
    volatile uint32_t AHB1SMENR;     // 0x68: AHB1 peripheral clocks enable in sleep mode register
    volatile uint32_t AHB2SMENR;     // 0x6C: AHB2 peripheral clocks enable in sleep mode register
    volatile uint32_t AHB3SMENR;     // 0x70: AHB3 peripheral clocks enable in sleep mode register
             uint32_t RESERVED6;     // 0x74: Reserved
    volatile uint32_t APB1SMENR1;    // 0x78: APB1 peripheral clocks enable in sleep mode register 1
    volatile uint32_t APB1SMENR2;    // 0x7C: APB1 peripheral clocks enable in sleep mode register 2
    volatile uint32_t APB2SMENR;     // 0x80: APB2 peripheral clocks enable in sleep mode register
             uint32_t RESERVED7;     // 0x84: Reserved
    volatile uint32_t CCIPR;         // 0x88: Peripherals independent clock configuration register
             uint32_t RESERVED8;     // 0x8C: Reserved
    volatile uint32_t BDCR;          // 0x90: Backup domain control register
    volatile uint32_t CSR;           // 0x94: Control/status register
    volatile uint32_t CRRCR;         // 0x98: Clock recovery RC register
} RCC_TypeDef;

// Create a pointer to the RCC structure
#define RCC ((RCC_TypeDef *) RCC_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configurePLL(void);
void configureClock(void);

#endif