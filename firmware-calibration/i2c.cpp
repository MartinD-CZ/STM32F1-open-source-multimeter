/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "i2c.h"
#include "delay.h"

uint8_t TXbuffer[TX_BUFFER_SIZE];
uint8_t TXpos;
uint8_t RXbuffer[RX_BUFFER_SIZE];

void i2c_init()
{
	//enable clock
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	
	//set GPIO to alternate mode, high speed, open drain
	GPIOB->MODER |= GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8 | GPIO_OSPEEDER_OSPEEDR9;
	GPIOB->AFR[1] |= (4 << 0) | (4 << 4);
	GPIOB->OTYPER |= GPIO_OTYPER_OT_8 | GPIO_OTYPER_OT_9;
	
	//set timings (SCLL, SCLH, SDADEL, SCLDEL)
	I2C1->TIMINGR = (0x9 << 0) | (0x3 << 8) | (0x1 << 16) | (0x3 << 20);
	
	//enable peripheral
	I2C1->CR1 |= I2C_CR1_PE;
}

void i2c_setSlaveAddress(uint8_t add)
{
	I2C1->CR2 = ((add & 0x7F) << 1);
}

void i2c_writeBuffer(uint8_t data)
{
	TXbuffer[TXpos++] = data;
}

void i2c_transmit()
{
	//set the NBYTES
	I2C1->CR2 |= (TXpos << 16) | (I2C_CR2_AUTOEND);
	
	//send start & address
	I2C1->CR2 |= I2C_CR2_START;
	
	//send data
	for (uint8_t pos = 0; pos < TXpos; pos++)
	{
		I2C1->TXDR = TXbuffer[pos];
		
		while ((I2C1->ISR & I2C_ISR_TXE) == 0);
	}
	
	TXpos = 0;
}

void i2c_request(uint8_t bytes)
{
	//set the NBYTES
	I2C1->CR2 |= (bytes << 16) | (I2C_CR2_AUTOEND) | (I2C_CR2_RD_WRN);
	
	//send start & address
	I2C1->CR2 |= I2C_CR2_START;
	
	//receive data
	for (uint8_t pos = 0; pos < bytes; pos++)
	{
		while ((I2C1->ISR & I2C_ISR_RXNE) == 0);
		
		RXbuffer[pos] = I2C1->RXDR;
	}
}

uint8_t i2c_readBuffer(uint8_t pos)
{
	return RXbuffer[pos];
}
