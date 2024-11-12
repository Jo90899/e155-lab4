// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// FLASH.h header file with structure definitition

#ifndef STM32L4_FLASH_H
#define STM32L4_FLASH_H

#include <stdint.h>

// Base addresses for GPIO
#define FLASH_BASE (0x40022000UL) // Flash Base address

// GPIO Struct:
typedef struct {
  volatile uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  volatile uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  volatile uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  volatile uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  volatile uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  volatile uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  volatile uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

#define FLASH ((FLASH_TypeDef *) FLASH_BASE)

void configureFlash(void);

#endif