/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "sdadc.h"
#include "delay.h"
#include "config.h"
#include "math.h"

volatile uint32_t SDADC_data[1000];

volatile int64_t sdadc_V_avg;
volatile int64_t sdadc_I_avg;
volatile uint64_t sdadc_V_rms;
volatile uint64_t sdadc_I_rms;
volatile uint16_t sdadc_samples;

volatile float sdadc_result_V_avg;
volatile float sdadc_result_V_rms;
volatile float sdadc_result_I_avg;
volatile float sdadc_result_I_rms;
volatile uint16_t sdadc_result_samples;

extern volatile bool screen_update, rangeI, aquisition;
extern volatile uint8_t rangeV;

volatile uint64_t frequency;

void SDADC_init(void)
{
	//enable clock & power
	RCC->CFGR |= RCC_CFGR_SDADCPRE_DIV12;
	RCC->APB2ENR |= RCC_APB2ENR_SDADC1EN | RCC_APB2ENR_SDADC2EN;
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_SDADC1EN | PWR_CR_SDADC2EN;
	
	//setup GPIO for analogue mode
	GPIOE->MODER |= GPIO_MODER_MODER8 | GPIO_MODER_MODER9;
	GPIOB->MODER |= GPIO_MODER_MODER0 | GPIO_MODER_MODER1;
	
	//turn on
	SDADC1->CR2 |= SDADC_CR2_ADON;
	SDADC2->CR2 |= SDADC_CR2_ADON;
	
	_delay_us(100);
	
	//enter init mode
	SDADC1->CR1 |= SDADC_CR1_INIT;
	SDADC2->CR1 |= SDADC_CR1_INIT;
	
	_delay_us(100);
	
	SDADC1->CR2 |= SDADC_CR2_RCONT;			//continuous mode
	SDADC2->CR2 |= SDADC_CR2_RCONT;
	
	SDADC1->CR1 |= SDADC_CR1_RDMAEN;		//DMA mode
	//SDADC2->CR1 |= SDADC_CR1_RDMAEN;
	
	SDADC2->CR1 |= SDADC_CR1_RSYNC;			//launch SDADC1 and 2 simulataneously
	
	SDADC1->CR2 |= (6 << 16);						//select channel 8 (current) for SDADC1
	SDADC2->CR2 |= (8 << 16);						//select channel 6 (voltage) for SDADC2
	
	SDADC1->CR2 |= SDADC_CR2_FAST;			//FAST mode
	SDADC2->CR2 |= SDADC_CR2_FAST;
	
	//setup SDADC2 CONF1 for 8x gain (60 mV voltage range)
	SDADC2->CONF1R |= SDADC_CONF1R_GAIN1_0 | SDADC_CONF1R_GAIN1_1;
	
	//exit initialization mode
	SDADC1->CR1 &= ~SDADC_CR1_INIT;
	SDADC2->CR1 &= ~SDADC_CR1_INIT;
	
	//setup DMA2 CH3
	//====================================================================================
	RCC->AHBENR |= RCC_AHBENR_DMA2EN;											//enable clock
	
	DMA2_Channel3->CCR |= DMA_CCR_PL_0 | DMA_CCR_PL_1;		//set priority to very high
	
	//enable DMA1 TC INT
	DMA2_Channel3->CCR |= DMA_CCR_TCIE;
	
	//set memory size to 32 bits
	DMA2_Channel3->CCR |= DMA_CCR_MSIZE_1;
	
	//set peripheral size to 32 bits
	DMA2_Channel3->CCR |= DMA_CCR_PSIZE_1;
	
	//increment memory
	DMA2_Channel3->CCR |= DMA_CCR_MINC;
	
	//set circular mode
	DMA2_Channel3->CCR |= DMA_CCR_CIRC;
	
	//1000 transfers
	DMA2_Channel3->CNDTR = 1000;
	
	//peripheral (source) address
	DMA2_Channel3->CPAR = (uint32_t)(&(SDADC1->RDATA12R));
	
	//memory (destination) address
	DMA2_Channel3->CMAR = (uint32_t)(SDADC_data);
	
	NVIC_SetPriority(DMA2_Channel3_IRQn, 2);
}

void SDADC_start(void)
{
	DMA2_Channel3->CCR |= DMA_CCR_EN;
	SDADC1->CR2 |= SDADC_CR2_RSWSTART;
	//SDADC2->CR2 |= SDADC_CR2_RSWSTART;
	NVIC_EnableIRQ(DMA2_Channel3_IRQn);
}

extern "C"
{
	void DMA2_Channel3_IRQHandler()
	{
		sdadc_samples++;
		
		for (uint16_t i = 0; i < 1000; i ++)
		{
			/*int16_t volt = (SDADC_data[i] & 0xFFFF);
			int16_t amp = (SDADC_data[i] >> 16) & 0xFFFF;*/
			int16_t amp = (SDADC_data[i] & 0xFFFF);
			int16_t volt = (SDADC_data[i] >> 16) & 0xFFFF;
			
			sdadc_V_avg += volt;
			sdadc_V_rms += volt * volt;
			sdadc_I_avg += amp;
			sdadc_I_rms += amp * amp;
		}
		
		DMA2->IFCR = DMA_IFCR_CTCIF3;
	}
	
	void TIM3_IRQHandler(void)
	{
		sdadc_result_samples = sdadc_samples * 1000;
		
		if (aquisition)
		{
			sdadc_result_V_avg = (float)sdadc_V_avg / sdadc_result_samples;
			sdadc_result_I_avg = (float)sdadc_I_avg / sdadc_result_samples;
		}
		else
		{
			sdadc_result_V_rms = sqrt((float)sdadc_V_rms / sdadc_result_samples);
			sdadc_result_I_rms = sqrt((float)sdadc_I_rms / sdadc_result_samples);
		}
		
		sdadc_V_avg = 0;
		sdadc_I_avg = 0;
		sdadc_V_rms = 0;
		sdadc_I_rms = 0;
		sdadc_samples = 0;
		
		frequency = TIM2->CNT * SCREEN_UPDATE_RATE;
		TIM2->CNT = 0x00;
		
		screen_update = true;
		
		TIM3->SR &=~TIM_SR_UIF;
	}
}
