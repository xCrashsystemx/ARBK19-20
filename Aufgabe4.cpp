#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>

volatile int32_t ms = 0;

void init() {
	DDRB = 0xff;
	
	TCCR0 = (1<<CS01);
	TIMSK = (1<<TOIE0);
	TCNT0 = 130;
	
	sei();
}

ISR(TIMER0_OVF_vect) {
	TCNT0 = 130;
	ms++;
}

void waitFor(int32_t waitTime) {
	waitTime += ms;
	while (waitTime != ms) {
		;
	}
}

void waitUntil(int32_t waitTime) {
	while (waitTime != ms) {
		;
	}
}

int main (void)
{
	init();
	
	while (true) {
		;
	}
}
