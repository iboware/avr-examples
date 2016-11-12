/*
 * serial.c
 *
 *  Created on: Nov 12, 2016
 *      Author: iboware
 */

#include "serial.h"

void USART_Init(unsigned int ubrr) {
	UBRR0H = (unsigned char) (ubrr >> 8);
	UBRR0L = (unsigned char) ubrr;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (3 << UCSZ00);
}
unsigned char USART_Receive(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}

void USART_Transmit(unsigned char data) {
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = data;
}

void USART_Putstring(char* StringPtr) {

	while (*StringPtr != 0x00) {
		USART_Transmit(*StringPtr);
		StringPtr++;
	}
}

void USART_Flush(void) {
	unsigned char dummy;
	while (UCSR0A & (1 << RXC0))
		dummy = UDR0;
}
