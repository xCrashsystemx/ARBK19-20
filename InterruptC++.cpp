#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

volatile bool gelb = true;
volatile bool rot = false;

void init() {
	DDRB = 0xff;
	DDRC = 0x00;
	PORTC = 0xff;
	
	TCCR0 = (1<<CS02)|(1<<CS00);
	TIMSK = (1<<TOIE0);
	GICR = (1<<INT0)|(1<<INT1);
	MCUCR = (1<<ISC00)|(1<<ISC01)|(1<<ISC10)|(1<<ISC11);
		
	sei();
}

ISR(INT0_vect) {
	gelb = !gelb;
	rot = false;
}

ISR(INT1_vect) {
	rot = !rot;
	gelb = false;
}

ISR(TIMER0_OVF_vect) {
	if (rot) {
			PORTB ^= (1 << PB0);
			PORTB &= ~(1<<PB1);
		} else if (gelb) {
			PORTB ^= (1 << PB1);
			PORTB &= ~(1<<PB0);
		} else {
			PORTB &= ~(1<<PB0);
			PORTB &= ~(1<<PB1);
		}
	}
}

int main (void)
{
	init();
	
	while (true) {
		;
	}
}
