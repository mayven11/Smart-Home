/*
 * SPI.c
 *
 * Created: 12/11/2020 9:36:52 PM
 *  Author: Dell
 */ 
#include <avr/io.h>
#include "SPI.h"

void SPI_Master_Init(void)
{
	DIO_vSetPinDir('B', 4, eOutPut);
	DIO_vSetPinDir('B', 5, eOutPut);
	DIO_vSetPinDir('B', 6, eInPut);
	DIO_vSetPinDir('B', 7, eOutPut);
	
	SPCR = 0x53;
}

void SPI_Slave_Init(void)
{
	DIO_vSetPinDir('B', 4, eInPut);
	DIO_vSetPinDir('B', 5, eInPut);
	DIO_vSetPinDir('B', 6, eOutPut);
	DIO_vSetPinDir('B', 7, eInPut);
	
	SPCR = 0x40;
}

void SPI_Master_Init_Trans(void)
{
	CLR_BIT(PORTB,4);
}

void SPI_Master_Ter_Trans(void)
{
	SET_BIT(PORTB,4);
}

uint8 SPI_Transiver(uint8 data)
{
	SPDR = data;
	while(READ_BIT(SPSR, 7) == 0 );
	return SPDR;
}


