// Joseph Abdelmalek
// jabdelmalek@hmc.edu
// 11/9/24
// main.c, Main file for Lab 4 to play music on a speaker


#include "RCC.h"
#include "GPIO.h"
#include "FLASH.h"
#include "TIMER.h"

#define PIN 6

// Pitch in Hz, duration in ms
const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

int main(void) {
    configureFlash();
    configureClock(); // configure clock
    RCC->AHB2ENR |= (1<<0); // Turn on clock to GPIOA
    RCC->APB2ENR |= (1<<16); // enable TIM15
    RCC->APB2ENR |= (1<<17); // enable TIM16

    configureTIM(TIM15); // configure TIM15
    configureTIM(TIM16); // configure TIM16
  

    pinSet(PIN, GPIO_ALT); // set GPIO A6 to alt function
    setAF(PIN, 0b1110); // set pin A6 to alt function 14
    while (1) {	
        for (int i = 0; i < sizeof(notes)/2; i++) {
          int freq = notes[i][0];
          int dur = notes[i][1];
          setFreq(freq, TIM16); // set the frequency for the note
          setDur(dur, TIM15); // play the note for the given duration
        }
    }

}