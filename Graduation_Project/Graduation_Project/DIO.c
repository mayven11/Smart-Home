/*
 * DIO.c
 *
 * Created: 12/11/2020 7:38:00 PM
 *  Author: Dell
 */ 

#include "DIO.h"
#include <avr/io.h>

void DIO_vSetPinDir(uint8 portName, uint8 pinNumber, DIRECTION dir)
{
	switch(portName)
	{
		case 'A':
		if(eOutPut == dir)
		{
			DDRA |= (1<<pinNumber);
		}
		else
		{
			DDRA &= ~(1<<pinNumber);
		}
		break;
		
		case 'B':
		if(eOutPut == dir)
		{
			DDRB |= (1<<pinNumber);
		}
		else
		{
			DDRB &= ~(1<<pinNumber);
		}
		break;
		
		case 'C':
		if(eOutPut == dir)
		{
			DDRC |= (1<<pinNumber);
		}
		else
		{
			DDRC &= ~(1<<pinNumber);
		}
		break;
		
		case 'D':
		if(eOutPut == dir)
		{
			DDRD |= (1<<pinNumber);
		}
		else
		{
			DDRD &= ~(1<<pinNumber);
		}
		break;
	}
}
void DIO_vWritePinDir(uint8 portName, uint8 pinNumber, DIRECTION dir)
{
	switch(portName)
	{
		case 'A':
		if(eOutPut == dir)
		{
			PORTA |= (1<<pinNumber);
		}
		else
		{
			PORTA &= ~(1<<pinNumber);
		}
		break;
		
		case 'B':
		if(eOutPut == dir)
		{
			PORTB |= (1<<pinNumber);
		}
		else
		{
			PORTB &= ~(1<<pinNumber);
		}
		break;
		
		case 'C':
		if(eOutPut == dir)
		{
			PORTC |= (1<<pinNumber);
		}
		else
		{
			PORTC &= ~(1<<pinNumber);
		}
		break;
		
		case 'D':
		if(eOutPut == dir)
		{
			PORTD |= (1<<pinNumber);
		}
		else
		{
			PORTD &= ~(1<<pinNumber);
		}
		break;
	}
	
}