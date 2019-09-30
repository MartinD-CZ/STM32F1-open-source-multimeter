/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "adc.h"
#include "config.h"

void adc1_init(void)
{
	//enable ADC clock
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	//pins PA0:2, PB1 as analog
	GPIOA->MODER |= GPIO_MODER_MODER0 | GPIO_MODER_MODER1 | GPIO_MODER_MODER2;
	GPIOB->MODER |= GPIO_MODER_MODER1;
	
	//sample time 239.5 cycles for channels 0:2
	ADC1->SMPR2 |= (7 << 0) | (7 << 3) | (7 << 6) | (7 << 24);
	
	//wake up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	
	//clear ADC calibration
	ADC1->CR2 |= ADC_CR2_RSTCAL;
	
	//launch ADC calibration
	ADC1->CR2 |= ADC_CR2_CAL;
	
	//wait for calibration complete
	while ((ADC1->CR2 & ADC_CR2_CAL) == ADC_CR2_CAL);
}

uint16_t adc1_getReading(uint8_t channel, uint8_t oversamplig)
{
	uint32_t data = 0;
	
	ADC1->SQR3 = channel;
	
	for (uint8_t i = 0; i < oversamplig; i ++)
	{
		ADC1->CR2 |= ADC_CR2_ADON;		//second ADON write = start conversion
		while ((ADC1->SR & ADC_SR_EOC) != ADC_SR_EOC);		//wait for conversion complete
		data += ADC1->DR;							//get data
	}
	
	return (data / oversamplig);
}
