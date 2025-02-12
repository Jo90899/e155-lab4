// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// GPIO.h header file with structure definitition

#ifndef STM32L4_GPIO_H
#define STM32L4_GPIO_H

#include <stdint.h>

// Base addresses for GPIO ports
#define GPIOA_BASE  (0x48000000UL)

// Arbitrary GPIO functions for pinMode()
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_ALT    2
#define GPIO_ANALOG 3

// GPIO struct
typedef struct {
    volatile uint32_t MODER;   // GPIO Offset 0x00 GPIO port mode register
    volatile uint32_t OTYPER;  // GPIO Offset 0x04
    volatile uint32_t OSPEEDR; // GPIO Offset 0x08
    volatile uint32_t PURPDR;  // GPIO Offset 0x0C
    volatile uint32_t IDR;     // GPIO Offset 0x10
    volatile uint32_t ODR;     // GPIO Offset 0x14
    volatile uint32_t BSRR;    // GPIO Offset 0x18
    volatile uint32_t LCKR;    // GPIO Offset 0x1C
    volatile uint32_t AFRL;    // GPIO Offset 0x20
    volatile uint32_t AFRH;    // GPIO Offset 0x24
} GPIO;

#define GPIOA ((GPIO *) GPIOA_BASE)
#define GPIO GPIOA

void pinSet(int pin, int function);
void setAF(int pin, int mode);

#endif