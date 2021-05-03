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
	if (p_value < 103) {
		tmpB = 0x01;
	} else if (p_value < 205) {
		tmpB = 0x02;
	} else if (p_value < 307) {
		tmpB = 0x04;
	} else if (p_value < 409) {
		tmpB = 0x08;
	} else if (p_value < 511) {
		tmpB = 0x10;
	} else if (p_value < 613) {
		tmpB = 0x20;
	} else if (p_value < 715) {
		tmpB = 0x40;
	} else {
		tmpB = 0x80;
	}
}

int main(void) {
	ADC_init();

	DDRB = 0xFF; PORTB = 0x00;

	unsigned short p_value;
	while (1) {
		p_value = ADC;
		TickFCT(p_value);
		PORTB = tmpB;
	}
	return 1;
}
