#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// FOR BARE METAL > BUZZER IS NOT WORKING

int main(void)
{
  //led
  //DDRB - DATA DIRECTION REFIGISTER FOR PORT B (12TH PIN IS THE PORT B PIN 4)
  DDRB |= (1<<DDB4); // MAKING THE 12 PIN AS OUTPUT MODE DDB4 REPRESENTS THE 12TH PIN
  // 1<<DDB4 - DDB4 REPRESENTS THE 4TH BIT WHICH MAKES 1 
  //DDRB HAS 00000000 (8 BIT) , THROUGH OR WHICH MAKES 1 

  //buzzer
  DDRD |= (1<<DDD2);  // MAKING THE PORT D PIN2 WHICH IS 2ND PIN IN THE UNO

  while(1)
  {
    //led
    //PORTB ^= (1<<PORTB4); // IT MAKES PIN 4 AS 1 , IT MAKES 0 THEN VICE VERSA

    //buzzer
    PORTD |= (1<<PORTD2); // IT MAKES PIN 2 AS 1 
    _delay_ms(500);
    PORTD &= ~(1<<PORTD2);// IT MAKES PIN 2 AS 0
    _delay_ms(500);
  }


  return 0;
}