/*
 * led.c
 *
 * Created: 2015/1/23 13:39:06
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"

void LedInit(void)
{
	#if(_LED_PIN == _LED_D5)
	DDRD |= (1<<PD5);
	#elif(_LED_PIN == _LED_C5)
	DDRC |= (1<<PC5);
	#endif
}

void LedOn(void)
{
	
	#if(_LED_PIN == _LED_D5)
	PORTD &= 0xdf;
	#elif(_LED_PIN == _LED_C5)
	PORTC &= 0xdf;
	#endif
}

void LedOff(void)
{
	
	#if(_LED_PIN == _LED_D5)
	PORTD |= (1<<PD5);
	#elif(_LED_PIN == _LED_C5)
	PORTC |= (1<<PC5);
	#endif
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

void WhiteLightOn(void)
{
	PORTB |= (1<<PB4);
}

void BlueLightOff(void)
{
	PORTB &= 0xDf;
}

void WhiteLightOff(void)
{
	

	PORTB &= 0xef;
}