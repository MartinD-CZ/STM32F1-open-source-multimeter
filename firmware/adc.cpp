//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "adc.h"
#include "defines.h"

volatile uint16_t adc_data[12];

void adc1_init(void)
{
	//ADC clock prescaler
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
	
	//enable ADC clock
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	//pins PA0:2 as analog
	GPIOA->CRL &=~(GPIO_CRL_CNF0_0 | GPIO_CRL_CNF1_0 | GPIO_CRL_CNF2_0);
	
	//sample time 28.5 cycles for channels 0, 1, 2
	//ADC1->SMPR2 |= (5 << 0) | (5 << 3) | (5 << 6);
	//ADC1->SMPR2 |= (4 << 0) | (4 << 3) | (4 << 6);
	ADC1->SMPR2 |= (3 << 0) | (3 << 3) | (3 << 6);
	
	//enable continuous mode
	ADC1->CR2 |= ADC_CR2_CONT;
	
	//enable scan mode
	ADC1->CR1 |= ADC_CR1_SCAN;
	
	//enable DMA mode
	ADC1->CR2 |= ADC_CR2_DMA;
	
	//convert CH0, CH1 and CH2
	ADC1->SQR1 = (11 << 20);
	ADC1->SQR3 = (0 << 0) | (1 << 5) | (2 << 10) | (0 << 15) | (1 << 20) | (2 << 25);
	ADC1->SQR2 = (0 << 0) | (1 << 5) | (2 << 10) | (0 << 15) | (1 << 20) | (2 << 25);
	
	//DMA SETUP
	//enable clock for DMA
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;
	
	//setup DMA1
	//set priority to very high
	DMA1_Channel1->CCR |= DMA_CCR1_PL_0 | DMA_CCR1_PL_1;
	
	//enable DMA1 TC INT
	DMA1_Channel1->CCR |= DMA_CCR1_TCIE;
	
	//set memory size to 16 bits
	DMA1_Channel1->CCR |= DMA_CCR1_MSIZE_0;
	
	//set peripheral size to 16 bits
	DMA1_Channel1->CCR |= DMA_CCR1_PSIZE_0;
	
	//increment memory
	DMA1_Channel1->CCR |= DMA_CCR1_MINC;
	
	//set circular mode
	DMA1_Channel1->CCR |= DMA_CCR1_CIRC;
	
	//12 transfers
	DMA1_Channel1->CNDTR = 12;
	
	//peripheral (source) address
	DMA1_Channel1->CPAR = (uint32_t)(&(ADC1->DR));
	
	//memory (destination) address
	DMA1_Channel1->CMAR = (uint32_t)(adc_data);
	
	NVIC_SetPriority(DMA1_Channel1_IRQn, 2);
}

void adc1_start(void)
{	
	NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
	//set DMA to 12 transfers
	DMA1_Channel1->CNDTR = 12;
	
	//start DMA
	DMA1_Channel1->CCR |= DMA_CCR1_EN;
	
	//wake up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	
	//clear ADC calibration
	ADC1->CR2 |= ADC_CR2_RSTCAL;
	
	//launch ADC calibration
	ADC1->CR2 |= ADC_CR2_CAL;
	
	while ((ADC1->CR2 & ADC_CR2_CAL) == ADC_CR2_CAL);
	
	//second ADON write = start conversion
	ADC1->CR2 |= ADC_CR2_ADON;
}

void adc1_stop(void)
{
	//disable ADC
	ADC1->CR2 &=~ADC_CR2_ADON;
	
	NVIC_DisableIRQ(DMA1_Channel1_IRQn);
	
	//disable DMA
	DMA1_Channel1->CCR &=~DMA_CCR1_EN;
}

void adc2_init(void)
{
	//enable ADC clock
	RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	
	//pins PA5:7, PB0 as analog
	GPIOA->CRL &=~(GPIO_CRL_CNF5_0 | GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_0);
	GPIOB->CRL &=~GPIO_CRL_CNF0_0;
	
	//sample time 239.5 cycles for channels 5, 6, 7, 8
	ADC2->SMPR2 |= (7 << 15) | (7 << 18) | (7 << 21) | (7 << 24);
	
	//wake up ADC
	ADC2->CR2 |= ADC_CR2_ADON;
	
	//clear ADC calibration
	ADC2->CR2 |= ADC_CR2_RSTCAL;
	
	//launch ADC calibration
	ADC2->CR2 |= ADC_CR2_CAL;
	
	//wait for calibration complete
	while ((ADC2->CR2 & ADC_CR2_CAL) == ADC_CR2_CAL);
}

uint16_t adc2_getReading(uint8_t channel, uint8_t oversamplig)
{
	uint16_t data = 0;
	
	switch(channel)
	{
		case VBAT: ADC2->SQR3 = (8 << 0); break;
		case TP1: ADC2->SQR3 = (5 << 0); break;
		case TP2: ADC2->SQR3 = (6 << 0); break;
		case TP3: ADC2->SQR3 = (7 << 0); break;
	}
	
	for (uint8_t i = 0; i < oversamplig; i ++)
	{
		ADC2->CR2 |= ADC_CR2_ADON;		//second ADON write = start conversion
		while ((ADC2->SR & ADC_SR_EOC) != ADC_SR_EOC);		//wait for conversion complete
		data += ADC2->DR;							//get data
	}
	
	return (data / oversamplig);
}
