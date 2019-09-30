/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "uart.h"
#include <stdio.h>
#include <stdarg.h>

#define UART_MSG_MAXLEN		128
char bufferTX[UART_MSG_MAXLEN];
volatile uint8_t TXPos;
volatile bool TX;

void uart_init(void)
{
	//enable clock
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	
	//setup GPIO: PA9 as TX, PA10 as RX
	GPIOA->MODER |= GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9 | GPIO_OSPEEDER_OSPEEDR10;
	GPIOA->AFR[1] |= (7 << 4) | (7 << 8);
		
	USART1->BRR = (468 << 4) | (12 << 0);	//BAUD 9600 @ F_CPU 72 Mhz
	//72000000 : (16 * 9600)
	
	//enable the USART, transmitter and receiver, and also the interrupt vector
	USART1->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

void uart_char(char ch)
{
	USART1->TDR = ch;
	
	while ((USART1->ISR & USART_ISR_TXE) != USART_ISR_TXE);
}

void uart_print(char *msg)
{
	while(*msg)  uart_char(*msg++);
}

void uart_printf(char *szFormat, ...)
{
	while (TX);
	va_list pArgs;
	va_start(pArgs, szFormat);
	vsnprintf(bufferTX, UART_MSG_MAXLEN - 1, szFormat, pArgs);
	va_end(pArgs);
	
	uart_print(bufferTX);
}
