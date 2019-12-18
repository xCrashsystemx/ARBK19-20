;
; Lauflicht.asm
;
; Created: 20.10.2019 11:41:52
; Author : leomu
;


; Replace with your application code
.include "m8def.inc"

.org 0x000
	rjmp start

start:
    ldi r16, LOW ( RAMEND )
	out SPL, r16
	ldi r16, HIGH ( RAMEND )
	out SPH, r16

	ldi r16, 0b00000111 ;set as output
	out DDRB, r16

main:
	ldi r16, 0b00000001
	out PORTB, r16
	rcall delay
	ldi r16, 0b00000000
	out PORTB, r16

	ldi r16, 0b00000010
	out PORTB, r16
	rcall delay
	ldi r16, 0b00000000
	out PORTB, r16

	ldi r16, 0b00000100
	out PORTB, r16
	rcall delay
	ldi r16, 0b00000000
	out PORTB, r16

	ldi r16, 0b00000010
	out PORTB, r16
	rcall delay
	ldi r16, 0b00000000
	out PORTB, r16
	
	rjmp main

delay:
	ldi r17, 2		;outer loop
	ldi r18, 5		;middle loop
	ldi r19, 255	;inner loop
loop:
	dec r19
	brne loop
	dec r18
	brne loop
	dec r17
	brne loop
	ret
