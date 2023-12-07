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
#include <string.h>


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

uint16_t notesAllStar[] = {        
//sloka
	(50<<8)+Gn,
        
	(25<<8)+Dn,
        (25<<8)+Hn,
        (50<<8)+Hn,

        (25<<8)+An,
        (25<<8)+Gn,
	(25<<8)+Gn,	

	(50<<8)+cn,
        (25<<8)+Hn,
        (25<<8)+Hn,

        (25<<8)+An,
        (25<<8)+An,

        (50<<8)+Gn,
	(25<<8)+Gn,

        (25<<8)+Dn,
        (25<<8)+Hn,
	(25<<8)+Hn,
        
	(25<<8)+An,
        (25<<8)+An,
	
	(25<<8)+Gn,
	(25<<8)+Gn,

	(50<<8)+En,
        (125<<8)+Dn,

	(25<<8)+Gn,
        (25<<8)+Gn,

	(25<<8)+Dn,
        (25<<8)+Hn,
        (25<<8)+Hn,

	(25<<8)+An,
        (25<<8)+An,

        (25<<8)+Gn,
	(25<<8)+Gn,	

	(50<<8)+cn,
        (25<<8)+Hn,
        (25<<8)+Hn,

        (25<<8)+An,
	(25<<8)+An,

        (25<<8)+Gn,
	(25<<8)+Gn,

        (50<<8)+Dn,
        (25<<8)+Hn,
	(25<<8)+Hn,
        
	(50<<8)+An,
        
	(25<<8)+Gn,
	(25<<8)+Gn,

	(50<<8)+An,

	(125<<8)+En,

//refrén
	(25<<8)+Hn,
	(50<<8)+Gn,
	
	(25<<8)+Gn,
	(25<<8)+En,
	(25<<8)+Gn,
	(50<<8)+Gn,

	(25<<8)+Gn,
	(25<<8)+En,
	(25<<8)+Gn,
	(50<<8)+Gn,

	(50<<8)+Gn,
	(75<<8)+Hn,
	
	(25<<8)+Hn,
	(50<<8)+Gn,
	
	(25<<8)+Gn,
	(25<<8)+En,
	(25<<8)+Gn,
	(50<<8)+Gn,

	(25<<8)+Gn,
	(25<<8)+En,
	(25<<8)+Gn,
	(50<<8)+Gn,

	(50<<8)+Gn,
	(50<<8)+Hn,
	(25<<8)+Dn,

	(50<<8)+Hn,
	(50<<8)+Dn,

	(25<<8)+cn,
	(25<<8)+Hn,
	(25<<8)+An,

	(50<<8)+An,
	(50<<8)+Gn,

	(25<<8)+Gn,
	(25<<8)+Gn,
	(25<<8)+An,
	(25<<8)+Gn,

	(25<<8)+Hn,
	(75<<8)+An,

	(25<<8)+An,
	(50<<8)+Gn,
	(25<<8)+An,
	(25<<8)+Hn,

	(200<<8)+En,
    };
	
uint16_t notesPiratesOfK[] = {
        (60<<8)+Dn,
        (30<<8)+Dn,

        (60<<8)+Dn,
        (30<<8)+Dn,

        (60<<8)+Dn,
        (30<<8)+Dn,
	
	(30<<8)+Dn,
        (30<<8)+An,
        (30<<8)+Cn,

        (60<<8)+Dn,
        (60<<8)+Dn,

        (30<<8)+Dn,
	(30<<8)+En,

        (60<<8)+Fn,
        (60<<8)+Fn,

        (30<<8)+Fn,
        (30<<8)+Gn,

        (60<<8)+En,
        (60<<8)+En,

        (30<<8)+Dn,
        (30<<8)+Cn,
        (30<<8)+Cn,

        (90<<8)+Dn,

	(30<<8)+An,
        (30<<8)+Cn,

        (60<<8)+Dn,
        (60<<8)+Dn,

        (30<<8)+Dn,
	(30<<8)+En,

        (60<<8)+Fn,
        (60<<8)+Fn,

        (30<<8)+Fn,
        (30<<8)+Gn,

        (60<<8)+En,
        (60<<8)+En,

        (30<<8)+Dn,
        (30<<8)+Cn,
        (90<<8)+Dn,
      };
    
uint16_t notesOverTheRainbow[] = {
        (132<<8)+cn,
        
		(99<<8)+En,
        (33<<8)+Dn,

        (49<<8)+Hn,
		(49<<8)+Hn,
		(33<<8)+Hn,

        (49<<8)+Dn,
        (49<<8)+Hn,
		(33<<8)+Dn,
	
		(165<<8)+cn,
        (49<<8)+cn,
        (49<<8)+cn,

        (255<<8)+cn,
        
		(132<<8)+cn,

        (132<<8)+cn,

		(49<<8)+Hn,
        (49<<8)+Hn,
        (33<<8)+Hn,

        (49<<8)+Dn,
        (115<<8)+Hn,

        (33<<8)+An,
        (33<<8)+cn,
		(165<<8)+cn,

		(33<<8)+An,
        (33<<8)+cn,
		(165<<8)+cn,

		(132<<8)+cn,

        (132<<8)+cn,

		(49<<8)+Hn,
        (49<<8)+Gn,
        (33<<8)+An,
	
		(66<<8)+Hn,
        (198<<8)+cn,

		(99<<8)+Cn,
        (33<<8)+An,

		(255<<8)+Gn,

	};
	
uint16_t notesbday[] = {
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

uint16_t notesInTheEnd[] = {
		//sloka
	      (60<<8)+Dn,
	      (60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	      (60<<8)+En,
	      (30<<8)+En,
	      (30<<8)+Fn,

	      (60<<8)+Dn,
        (60<<8)+An,
	      (60<<8)+An,
	      (60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	      (60<<8)+En,
	      (30<<8)+En,
	      (30<<8)+Fn,

	      (60<<8)+Dn,
	      (60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	      (60<<8)+En,
	      (30<<8)+En,
	      (30<<8)+Fn,
      
	      (60<<8)+Dn,
	      (60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (240<<8)+En,
//refren
	(30<<8)+An,
	(60<<8)+Cn,
	(60<<8)+Dn,

	(90<<8)+En,
	(30<<8)+En,
	(45<<8)+En,
	
	(45<<8)+cn,
	(180<<8)+cn,
	
	(30<<8)+Cn,	
	(30<<8)+Dn,
	(120<<8)+En,

	(30<<8)+Dn,
	(15<<8)+En,
	(15<<8)+Dn,
	(30<<8)+En,

	(30<<8)+Fn,
	(60<<8)+En,
	(60<<8)+Dn,


	(30<<8)+An,
	(60<<8)+Cn,
	(60<<8)+Dn,

	(90<<8)+En,
	(30<<8)+En,
	(45<<8)+En,
	
	(45<<8)+cn,
	(180<<8)+cn,
	
	(30<<8)+Cn,	
	(30<<8)+Dn,
	(120<<8)+En,

	(30<<8)+Dn,
	(15<<8)+En,
	(15<<8)+Dn,
	(30<<8)+En,

	(30<<8)+Dn,
	(60<<8)+Fn,

	(30<<8)+En,
	(30<<8)+Dn,
	(120<<8)+cn, 
    };


char songNames[][10] = {"All-star", "PotC", "Over the rainbow", "Happy Birthday", "In the End"};
//uint16_t notesArr[] = {notesAllStar, notesPiratesOfK, notesbday, notesInTheEnd, notesOverTheRainbow};

	uint8_t notei = 0;
	uint8_t songNum = 1;
    // Infinite loop
    while (1)
    {
      _delay_ms(50);
	
	// uint16_t szis = sizeof(arrrrr[songNum])/sizeof(arrrrr[songNum][0]);
	// uint16_t ULTIMATEARRAY[szis];
	// memcpy(ULTIMATEARRAY, notesbday, (szis) * 2);

	// notei = 0;
	// oled_clrscr();
	// oled_gotoxy(1,2);
	// oled_puts(songNames[songNum]);
	// oled_display();




	//   for (uint16_t i = 0; i<sizeof(ULTIMATEARRAY)/sizeof(ULTIMATEARRAY[0]); i++)
    //   {
    //     play_note_endian(ULTIMATEARRAY[i]);
	// 	if(ULTIMATEARRAY[i] != 0){
    //     draw_note(ULTIMATEARRAY[i] & 0xff, notei);}
    //     notei++;
    //     notei %=21;
    //   }

	// songNum++;
	// songNum %= 5;


	// notei = 0;
	// oled_clrscr();
	// oled_gotoxy(1,2);
	// oled_puts("All-Star");
	// oled_display();

	// for (uint16_t i = 0; i<sizeof(notesAllStar)/sizeof(notesAllStar[0]); i++)
    //   {
    //     play_note_endian(notesAllStar[i]);
    //     draw_note(notesAllStar[i] & 0xff, notei);
    //     notei++;
    //     notei %=21;
    //   }

	// notei = 0;
	// oled_clrscr();
	// oled_gotoxy(1,2);
	// oled_puts("Over The Rainbow");
	// oled_display();

	// for (int i = 0; i<sizeof(notesOverTheRainbow) / sizeof(notesOverTheRainbow[0]); i++)
    //   {
    //     play_note_endian(notesOverTheRainbow[i]);
    //     draw_note(notesOverTheRainbow[i] & 0xff, notei);
    //     notei++;
    //     notei %=21;
    //   }

	notei = 0;
	_delay_ms(1000);
	oled_clrscr();
	oled_gotoxy(1,2);
	oled_puts("Now playing:");
	oled_gotoxy(1,3);
	oled_puts("Pirates Of the");
	oled_gotoxy(1,4);
	oled_puts("Caribbean");
	oled_display();

	for (uint16_t i = 0; i<sizeof(notesPiratesOfK)/sizeof(notesPiratesOfK[0]); i++)
      {
        play_note_endian(notesPiratesOfK[i]);
        draw_note(notesPiratesOfK[i] & 0xff, notei);
        notei++;
        notei %=21;
      }

	notei = 0;
	_delay_ms(1000);
	oled_clrscr();
	oled_gotoxy(1,2);
	oled_puts("Now playing:");
	oled_gotoxy(1,3);
	oled_puts("Happy birthday");
	oled_display();

	for (uint16_t i = 0; i<sizeof(notesbday)/sizeof(notesbday[0]); i++)
      {
        play_note_endian(notesbday[i]);
        draw_note(notesbday[i] & 0xff, notei);
        notei++;
        notei %=21;
      }

	notei = 0;
	_delay_ms(1000);
	oled_clrscr();
	oled_gotoxy(1,2);
	oled_puts("Now playing:");
	oled_gotoxy(1,3);
	oled_puts("In The End");
	oled_display();

	for (uint16_t i = 0; i<sizeof(notesInTheEnd)/sizeof(notesInTheEnd[0]); i++)
      {
        play_note_endian(notesInTheEnd[i]);
        draw_note(notesInTheEnd[i] & 0xff, notei);
        notei++;
        notei %=21;
      }



	notei = 0;
	_delay_ms(1000);

    
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






