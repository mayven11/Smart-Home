/*
 * DIO.h
 *
 * Created: 12/11/2020 7:38:33 PM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_

#define uint8 unsigned char
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define READ_BIT(reg,num) ( ((reg & (1<<num)) >>num))
#define ROR(reg,num) ( (reg >> num) | (reg << (REG_SIZE - num)) )
#define ROL(reg,num) ( (reg << num) | (reg >> (REG_SIZE - num)) )
#define TOG_BIT(reg,bit) (reg^=(1<<bit))
typedef enum{eInPut , eOutPut} DIRECTION; 

void DIO_vSetPinDir(uint8 portName, uint8 pinNumber, DIRECTION dir);
void DIO_vWritePinDir(uint8 portName, uint8 pinNumber, DIRECTION dir);

#endif /* DIO_H_ */