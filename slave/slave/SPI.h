/*
 * SPI.h
 *
 * Created: 12/11/2020 9:37:06 PM
 *  Author: Dell
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Master_Init_Trans(void);
void SPI_Master_Ter_Trans(void);
uint8 SPI_Transiver(uint8 data);

#endif /* SPI_H_ */