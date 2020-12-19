/*
 * UART.h
 *
 * Created: 12/11/2020 8:59:20 PM
 *  Author: Dell
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <avr/delay.h>
#define uint8 unsigned char
//#define uint16 unsigned char
//#define NOT_PRESSED 0xFF
//#define SET_BIT(reg,bit) (reg|=(1<<bit))
//#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
//#define READ_BIT(reg,num) ( ((reg & (1<<num)) >>num))
//#define ROR(reg,num) ( (reg >> num) | (reg << (REG_SIZE - num)) )
//#define ROL(reg,num) ( (reg << num) | (reg >> (REG_SIZE - num)) )
//#define TOG_BIT(reg,bit) (reg^=(1<<bit))

void HC05_vSend(uint8 data);
void HC05_vInit(void);
void UART_vSend(uint8 data);
void UART_vInit(unsigned long baud);
void HC05_vPrint(unsigned char *str);

#endif /* UART_H_ */