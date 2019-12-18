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
	sei();
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

int main (void)
{
	init();
	
	while (true) {
		if (PINC & (1 << PC1)) {
			gelb = !gelb;
			rot = false;
		} else if (PINC & (1 << PC2)) {
			rot = !rot;
			gelb = false;
		}
	}
}
