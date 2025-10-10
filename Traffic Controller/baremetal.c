#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// redPin - 13 pin - PB5
// greenPin - 12 pin - PB4
// bluePin - 8 pin - PB0

int main(void)
{
  // OUTPUT MODE
  DDRB |= (1<<DDB5) | (1<<DDB4) | (1<<DDB0); 


  while(true)
  {
      // RED ON
      PORTB |= (1<<PB5);
      _delay_ms(5000);
      // YELLOW ON
      PORTB |= (1<<PB5) | (1<<PB4);
      _delay_ms(5000);
      // GREEN ON
      PORTB &= ~(1<<PB5);
      PORTB |= (1<<PB4);
      _delay_ms(5000);
      PORTB &= ~(1<<PB4);
  }
  return 0;
}