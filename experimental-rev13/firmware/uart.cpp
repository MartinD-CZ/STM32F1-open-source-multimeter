//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0 International
// ===================================================

#include "stm32f10x.h"
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
	
	//remap the USART1 pins
	AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;
	
	//setup GPIO: PB6 as TX, PB7 as RX
	GPIOB->CRL |= GPIO_CRL_MODE6 | GPIO_CRL_CNF6_1;
	GPIOB->CRL &=~GPIO_CRL_CNF6_0;
		
	USART1->BRR = (468 << 4) | (12 << 0);	//BAUD 9600 @ F_CPU 72 Mhz
	//72000000 : (16 * 9600)
	
	//enable the USART, transmitter and receiver, and also the interrupt vector
	USART1->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_TCIE;
	
	NVIC_SetPriority(USART1_IRQn, 6);
	NVIC_EnableIRQ(USART1_IRQn);
}

void uart_print(char *msg)
{
	while (TX);
	TXPos = 0;
	int16_t i = -1;
	while (msg[++i] != '\0')
		bufferTX[i] = msg[i];
	for (; i < UART_MSG_MAXLEN; i ++)
		bufferTX[i] = 0;
	
	TX = true;
	USART1->DR = bufferTX[TXPos++];
}

void uart_printf(char *szFormat, ...)
{
	while (TX);
	va_list pArgs;
	va_start(pArgs, szFormat);
	vsnprintf(bufferTX, UART_MSG_MAXLEN - 1, szFormat, pArgs);
	va_end(pArgs);
	
	TX = true;
	TXPos = 0;
	USART1->DR = bufferTX[TXPos++];
}

extern "C"
{
	void USART1_IRQHandler(void)
	{
		//transmission complete
		if ((USART1->SR & USART_SR_TC) == USART_SR_TC)
		{
			if (bufferTX[TXPos] != 0)
				USART1->DR = bufferTX[TXPos++];
			else
				TX = false;
			
			USART1->SR &=~USART_SR_TC;
		}
	}
}
