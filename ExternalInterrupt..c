/*
 * ExternalInterrupt..c
 *
 *  Created on: Aug 15, 2018
 *  Author: Ahmad Ganzouri
 *
 */
#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char num =0;

ISR(INT2_vect){

	if (num == 9)
	{
		num=0;
	}
	else
	{
	num++;
	}

	PORTC = ( PORTC & 0xF0) | (num & 0x0F);


}

void INT2_Init(void){
	SREG   &= ~(1<<7);
	DDRB   &= ~(1<<PB2); // init PB2 input pin
	GICR   |= (1<<INT2); // enable INT2 interrupt
	MCUCSR |= (1<<ISC2); // rising edge interrupt
	SREG   |= (1<<7);  // I-bit enabled


}



void main (void)
{
	INT2_Init();

	DDRC |= 0x0F;
	PORTC = ( PORTC & 0xF0);

	while(1)
	{

	}

}


