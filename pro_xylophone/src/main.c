/***********************************************************************
 * 
 * Use USART unit and transmit data between ATmega328P and computer.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif

/**********NOTE DEFINITIONS*******************************/
#define Cn PD2 
#define Dn PD3
#define En PD4
#define Fn PD5
#define Gn PD6
#define An PD7
#define Hn PB0
#define cn PB1
/*********************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <gpio.h>           // Peter Fleury's UART library
#include <gpio.c>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions
#include <util/delay.h> // Functions for busy-wait delay loops


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and transmit UART data four times 
 *           per second.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize USART to asynchronous, 8N1, 9600

    
    // Configure 16-bit Timer/Counter1 to transmit UART data
    // Set prescaler to 262 ms and enable overflow interrupt
    TIM1_OVF_262MS
    TIM1_OVF_ENABLE

    // Enables interrupts by setting the global interrupt mask
    sei();

    GPIO_mode_output(&DDRD, PD2);
    GPIO_mode_output(&DDRD, PD3);
    GPIO_mode_output(&DDRD, PD4);
    GPIO_mode_output(&DDRD, PD5);
    GPIO_mode_output(&DDRD, PD6);
    GPIO_mode_output(&DDRD, PD7);
    GPIO_mode_output(&DDRB, PB0);
    GPIO_mode_output(&DDRB, PB1);



    uint8_t uptime = 0;
    // Infinite loop
    while (1)
    {
      _delay_ms(50);
      
      /*if (uptime == 0){
        uptime = 1;
        GPIO_write_high(&PORTD, PD2);
      }
      else{
        uptime = 0;
        GPIO_write_low(&PORTD, PD2);
      }*/

      play_note(Cn);
      _delay_ms(50);
      play_note(Dn);
      _delay_ms(50);
      play_note(En);
      _delay_ms(50);
      play_note(Fn);
      _delay_ms(50);
      play_note(Gn);
      _delay_ms(50);
      play_note(An);
      _delay_ms(50);
      play_note(Hn);
      _delay_ms(50);
      play_note(cn);
      _delay_ms(50);

        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Transmit UART data four times per second.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{

  // uint8_t up_time = 0;
  // uint8_t down_time = 0;
  //   if(down_time >= 10)
  //   {
  //     GPIO_write_high(&PORTB, C_small);
  //     down_time = 0;
  //     up_time++;
  //   }
  //   else if (up_time >= 10)
  //   {
  //     GPIO_write_low(&PORTB, PB1);
  //     up_time = 0;
  //     down_time++;
  //   }
    
    
    
}

void play_note(uint8_t note) //uint8_t postdelay = 50
{
  if(note == PB0 || note == PB1){
  GPIO_write_high(&PORTB, note);
  _delay_ms(10);
  GPIO_write_low(&PORTB, note);}
  else{
    GPIO_write_high(&PORTD, note);
  _delay_ms(10);
  GPIO_write_low(&PORTD, note);
  }
  //_delay_ms(postdelay);
}



