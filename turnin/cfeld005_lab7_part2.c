/*	Author: Cote Feldsine
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpB, tmpD;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) ;
}

void TickFCT(unsigned short p_value) {
	tmpB = (char) p_value;
	tmpD = (char) (p_value >> 8);
}

int main(void) {
	ADC_init();

	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned short p_value;
	while (1) {
		p_value = ADC;
		TickFCT(p_value);
		PORTB = tmpB;
		PORTD = tmpD;
	}
	return 1;
}
