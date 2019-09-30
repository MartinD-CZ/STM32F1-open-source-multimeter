#include "stm32f3xx.h"
#include "sdadc3.h"
#include "delay.h"
#include "config.h"
#include "math.h"

void SDADC3_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_SDADC3EN;
	PWR->CR |= PWR_CR_SDADC3EN;
	
	//setup GPIO for analogue mode
	GPIOB->MODER |= GPIO_MODER_MODER14 | GPIO_MODER_MODER15;
	
	//turn on
	SDADC3->CR2 |= SDADC_CR2_ADON;
	
	_delay_us(100);
	
	//enter init mode
	SDADC3->CR1 |= SDADC_CR1_INIT;
	
	_delay_us(100);
	
	SDADC3->CR2 |= SDADC_CR2_RCONT;							//continuous mode
	
	SDADC3->CR2 |= (8 << 16);										//select channel 8 (voltage) for SDADC1
	
	SDADC3->CR2 |= SDADC_CR2_FAST;							//FAST mode
	
	SDADC3->CONF0R |= SDADC_CONF0R_COMMON0_0;		//set common mode for calibration
	
	//exit initialization mode
	SDADC3->CR1 &= ~SDADC_CR1_INIT;
	
	//start calibration
	SDADC3->CR2 |= SDADC_CR2_STARTCALIB;
	while (SDADC3->ISR & SDADC_ISR_CALIBIP);
}

void SDADC3_start(void)
{
	SDADC3->CR2 |= SDADC_CR2_RSWSTART;
}
