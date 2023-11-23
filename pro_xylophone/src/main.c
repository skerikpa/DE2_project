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

#define dl200ms = 200
/*********************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <gpio.h>           // Peter Fleury's UART library
#include <gpio.c>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <lcd.h>            // Peter Fleury's LCD library
#include <oled.h>
#include <xylo.h>


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

    oled_init(OLED_DISP_ON);
    oled_clrscr();

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




    uint16_t notesArr[] = {
        (20<<8)+Cn,
        (20<<8)+Cn,
        (40<<8)+Dn,
        (40<<8)+Cn,
        (40<<8)+Fn,
        (80<<8)+En,

        (20<<8)+Cn,
        (20<<8)+Cn,
        (40<<8)+Dn,
        (40<<8)+Cn,
        (40<<8)+Gn,
        (80<<8)+Fn,

        (20<<8)+Cn,
        (20<<8)+Cn,
        (40<<8)+cn,
        (40<<8)+An,
        (40<<8)+Fn,
        (40<<8)+En,
        (40<<8)+Dn,

        (20<<8)+cn,
        (20<<8)+cn,
        (40<<8)+An,
        (40<<8)+Fn,
        (40<<8)+Gn,
        (80<<8)+Fn,
      };

    uint8_t notei = 0;
    // Infinite loop
    while (1)
    {
      _delay_ms(50);

         for (uint16_t i = 0; i<sizeof(notesArr); i++)
      {
        play_note_endian(notesArr[i]);
        draw_note(notesArr[i] & 0xff, notei);
        notei++;
        notei %=21;
      }
      
        oled_display();
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

}






