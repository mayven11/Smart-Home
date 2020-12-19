/*
 * UART.c
 *
 * Created: 12/11/2020 8:16:11 PM
 *  Author: Dell
 */ 
#include <avr/io.h>
#include "UART.h"
#include "DIO.h"

void UART_vInit(unsigned long baud)
{
	/* set baud rate in UBRRL - UBRRH*/
	
	unsigned short temp = (((F_CPU)/ (16*baud) ) -1);
	UBRRL = (char) temp;
	UBRRH = (char) (temp >> 8);
	
	/*Choose Frame 8 bit/1 stop/no parity*/
	UCSRC =(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	
	/*Enable interrupt Reception*/
	UCSRB =(1<<RXCIE);
	
	
	
	/*Enable UART Rx/Tx */
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	/*Enable Global I-bit*/
	
	sei();
}

void UART_vSend(uint8 data)
{
	//while(UCSRA & (1<<UDRE)== 0); /*Waiting*/
	UDR = data; 
	
	while(READ_BIT(UCSRA,5) == 0);
}


/* Bluetooth*/

void HC05_vInit(void)
{
	UART_vInit(9600);
}

void HC05_vSend(uint8 data)
{
	UART_vSend(data);
}
void HC05_vPrint(unsigned char *str)
{
	unsigned char *ptr= str;
	while(*ptr)
	{
		HC05_vSend(*ptr++);
	}
}