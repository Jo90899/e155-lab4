// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// GPIO.c file with pinSet and setAF functions

#include "GPIO.h"

// Set the pin mode for the function
void pinSet(int pin, int function) {
    switch(function) {
        case GPIO_INPUT:
            GPIO->MODER &= ~(0b11 << 2*pin);
            break;
        case GPIO_OUTPUT:
            GPIO->MODER |= (0b1 << 2*pin);
            GPIO->MODER &= ~(0b1 << (2*pin+1));
            break;
        case GPIO_ALT:
            GPIO->MODER &= ~(0b1 << 2*pin);
            GPIO->MODER |= (0b1 << (2*pin+1));
            break;
        case GPIO_ANALOG:
            GPIO->MODER |= (0b11 << 2*pin);
            break;
    }
}

void setAF(int pin, int mode) {
    GPIO->AFRL &= ~(0b1111<<4*pin);
    GPIO->AFRL |= (mode<<4*pin);

}