/*
 * TimerC1.c
 *
 *  Created on: Aug 15, 2018
 *  Author: Ahmad Ganzouri
 *
 */


#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>
#define NUMBER_OF_TICKS 123

unsigned char num =0;
unsigned char tick=0;

ISR(TIMER0_OVF_vect)
{
    tick++;
	if (tick == NUMBER_OF_TICKS)
	{
	        if (num == 9)
	        {
		    num=0;
	        }
	        else
	        {
	        num++;
	        }

	        PORTC = ( PORTC & 0xF0) | (num & 0x0F);
	        tick =0;
	}

}

void Timer0_Init_NormalMode(void){

	TCNT0 = 0;
	TIMSK |= (1<<TOIE0);
	TCCR0 = (1<<FOC0) | (1<<CS02);


}




int main (void)
{
	DDRC |= 0x0F;
	PORTC = ( PORTC & 0xF0);
	SREG  |= (1<<7);
	Timer0_Init_NormalMode();

	while(1)
	{

	}

}
