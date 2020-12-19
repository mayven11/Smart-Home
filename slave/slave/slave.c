/*
 * slave.c
 *
 * Created: 12/11/2020 9:36:18 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include "SPI.h"
#include "DIO.h"

int main(void)
{
	
	uint8 recived_data = 0;
	uint8 trans_data = 1;
	DIO_vSetPinDir('D' , 3 , eOutPut);
	CLR_BIT(PORTD , 3);
	DIO_vSetPinDir('C' , 2 , eOutPut);
	CLR_BIT(PORTC , 2);
	SPI_Slave_Init();
	_delay_ms(1000);
    while(1)
    {
		recived_data = SPI_Transiver(trans_data); /*the received data transmitted from the Master and send it's data to the Master*/
		if( recived_data == '1')
		{
			TOG_BIT(PORTC , 2);
		}
		else if(recived_data == '2')
		{
			TOG_BIT(PORTD , 3);
		}
		recived_data = 0;
    }
}