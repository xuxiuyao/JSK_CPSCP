/*
 * led.c
 *
 * Created: 2015/1/23 13:39:06
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"

void LedInit(void)
{
	DDRD |= (1<<5);
	
}

void LedOn(void)
{
	PORTD &= 0xdf;
}

void LedOff(void)
{
	PORTD |= (1<<PD5);
}

void LedFlashing(uint8_t times)
{
	uint8_t i = 0;
	
	for (i = 0; i < times; i++)
	{
		LedOff();
		_delay_ms(250);
		LedOn();
		_delay_ms(250);
	}
}

void BlueLightOn(void)
{
	PORTB |= (1<<PB5);
}

void BlueLightOff(void)
{
	PORTB |= (1<<PB4);
}

void WhiteLightOn(void)
{
	PORTB &= 0xDf;
}

void WhiteLightOff(void)
{
	

	PORTB &= 0xef;
}