#include <xylo.h>
#include <avr/io.h>         // AVR device-specific IO definitions

void play_note_endian(uint16_t delay_note) 
{
  if (delay_note == 0)
  {
    return;
  }
  
  uint8_t delay = delay_note >> 8;
  uint8_t note = delay_note & 0xff;
  if(note == PB0 || note == PB1){
  GPIO_write_high(&PORTB, note);
  _delay_ms(30);
  GPIO_write_low(&PORTB, note);}
  else{
    GPIO_write_high(&PORTD, note);
  _delay_ms(30);
  GPIO_write_low(&PORTD, note);
  }
  if (delay > 0){
    for(uint8_t i=0; i<delay-10; i++){
      _delay_ms(10);
    }
  }
  else{
    _delay_ms(200);
  }
}

void draw_note(uint8_t note, uint8_t pos){
  oled_gotoxy(pos+1,0);
  oled_putc(' ');
  oled_gotoxy(pos,0);
  switch (note)
  {
  case PD2:   
    oled_putc('C');
    break;
  case PD3:
    oled_putc('D');
    break;
  case PD4:
    oled_putc('E');
    break;
  case PD5:
    oled_putc('F');
    break;
  case PD6:
    oled_putc('G');
    break;
  case PD7:
    oled_putc('A');
    break;
  case PB0:
    oled_putc('H');
    break;
  case PB1:
    oled_putc('c');
    break;
  default:
    break;
  }
    oled_display();

}