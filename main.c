/*
 * main.c
 *
 *  Created on: Nov 10, 2016
 *      Author: iboware
 */
#include <avr/io.h>
#include <util/delay.h>
#include <ctype.h>
#include "serial.h"

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)

int main(void) {
	USART_Init(BAUD_PRESCALER);
	USART_Flush();

	unsigned char usartChar;
	DDRB |= (1 << PB5);
	while (1) {
		_delay_ms(50);
		usartChar = USART_Receive();
		if (usartChar != 0x00) {
			if (isalpha(usartChar)) {
				if (usartChar >= 'a' && usartChar <= 'z') {
					USART_Transmit(toupper(usartChar));
				} else {
					USART_Transmit(tolower(usartChar));
				}
			} else if (isdigit(usartChar)) {
				unsigned int numberOfBlink = usartChar - '0';
				while (numberOfBlink > 0) {
					PORTB |= (1 << PB5);
					_delay_ms(300);
					PORTB &= ~(1 << PB5);
					_delay_ms(200);

					numberOfBlink--;
				}

			} else {
				USART_Putstring("ERROR\n");
			}

		}
	}

	return 0;
}
