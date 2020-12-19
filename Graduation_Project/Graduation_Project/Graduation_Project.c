/*
 * Graduation_Project.c
 *
 * Created: 12/11/2020 7:37:18 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "SPI.h"
#include "UART.h"

volatile unsigned char rxdata=0;

volatile unsigned char Bluetooth_Data=0;

ISR(USART_RXC_vect)
{
	Bluetooth_Data = 1;
	rxdata = UDR;
}

int main(void)
{
	uint8 rec_data = 0;
	HC05_vInit();
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	_delay_ms(1000);
	
    while(1)
    {
        
		if(Bluetooth_Data == 1 )
		{
			
			Bluetooth_Data = 0;
		 
			rec_data = SPI_Transiver(rxdata); /*Transmit the received data from the HC05 to the slave and receive the data of the slave*/
			
			_delay_ms(1000);
		}			
    }
}