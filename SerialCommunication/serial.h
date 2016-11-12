/*
 * serial.h
 *
 *  Created on: Nov 12, 2016
 *      Author: iboware
 */

#ifndef SERIAL_H_
#define SERIAL_H_
#include <avr/io.h>
void USART_Init(unsigned int ubrr);
unsigned char USART_Receive(void);
void USART_Transmit(unsigned char data);
void USART_Putstring(char* StringPtr);
void USART_Flush(void);
#endif /* SERIAL_H_ */
