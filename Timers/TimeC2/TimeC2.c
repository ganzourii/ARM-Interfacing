/*
 * TimeC2.c
 *
 *  Created on: Aug 15, 2018
 *  Author: Ahmad Ganzouri
 *
 */

#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>

void Timer0_Init_PWM(void){

	TCNT0 = 0;
	DDRB |= (1 << PB3);
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS01);
	OCR0 = 128;

}



int main (void)
{
	Timer0_Init_PWM();
	while(1)
	{

	}
}
