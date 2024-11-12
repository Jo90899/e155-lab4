// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// FLASH.c with configureFlash function

#include "FLASH.h"

void configureFlash() {
    FLASH->ACR |= (0b100);    // Configure to have 4 wait-states
    FLASH->ACR |= (1 << 8);   // Turn on ART
}