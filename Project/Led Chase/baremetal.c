#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
  //pin in order - 2, 4, 7, 8, 12

  // B -> 8 - 13 | D -> 0 - 7

  // pin mode declaration - OUTPUT MODE
  DDRB |= (1<<DDB0); // pin 8
  DDRB |= (1<<DDB4); // pin 12
  DDRD |= (1<<DDD7); // pin 7
  DDRD |= (1<<DDD4); // pin 4
  DDRD |= (1<<DDD2); // pin 2

  while(1)
  {
      //FORWARD
      PORTD |= (1<<PORTD2);
      _delay_ms(200);
      PORTD &= ~(1<<PORTD2);
      _delay_ms(200);
      PORTD |= (1<<PORTD4);
      _delay_ms(200);
      PORTD &= ~(1<<PORTD4);
      _delay_ms(200);
      PORTD |= (1<<PORTD7);
      _delay_ms(200);
      PORTD &= ~(1<<PORTD7);
      _delay_ms(200);
      PORTB |= (1<<PORTB0);
      _delay_ms(200);
      PORTB &= ~(1<<PORTB0);
      _delay_ms(200);
      PORTB |= (1<<PORTB4);
      _delay_ms(200);
      PORTB &= ~(1<<PORTB4);
      _delay_ms(200);

      //BACKWARD
      PORTB |= (1<<PORTB0);
      _delay_ms(200);
      PORTB &= ~(1<<PORTB0);
      _delay_ms(200);
      PORTD |= (1<<PORTD7);
      _delay_ms(200);
      PORTD &= ~(1<<PORTD7);
      _delay_ms(200);
      PORTD |= (1<<PORTD4);
      _delay_ms(200);
      PORTD &= ~(1<<PORTD4);
      _delay_ms(200);
  }
  

  return 0;
}