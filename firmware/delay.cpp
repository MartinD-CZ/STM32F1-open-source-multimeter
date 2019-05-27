//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "delay.h"

void _delay_ms(uint16_t ms)
{
	//set prescaler (63999 + 1)
	TIM4->PSC = 63999;
	
	//update registers
	TIM4->EGR |= TIM_EGR_UG;
	
	//zero the counter
	TIM4->CNT = 0x00;
	
	//enable timer
	TIM4->CR1 |= TIM_CR1_CEN;
	
	//wait for compare
	while (ms > TIM4->CNT);
		
	//disable timer
	TIM4->CR1 &=~TIM_CR1_CEN;
}

void _delay_us(uint16_t us)
{
	//set prescaler (63 + 1)
	TIM4->PSC = 63;
	
	//update registers
	TIM4->EGR |= TIM_EGR_UG;
	
	//zero the counter
	TIM4->CNT = 0x00;
	
	//enable timer
	TIM4->CR1 |= TIM_CR1_CEN;
	
	//wait for compare
	while (us > TIM4->CNT);
		
	//disable timer
	TIM4->CR1 &=~TIM_CR1_CEN;
}

void _delay_init(void)
{
	//enable clock to Timer 4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
}

void _count_us_start(void)
{
	//set prescaler (63 + 1)
	TIM4->PSC = 63;
	
	//update registers
	TIM4->EGR |= TIM_EGR_UG;
	
	//zero the counter
	TIM4->CNT = 0x00;
	
	//enable timer
	TIM4->CR1 |= TIM_CR1_CEN;
}

uint16_t _count_us_stop(void)
{
	//disable timer
	TIM4->CR1 &=~TIM_CR1_CEN;
	
	return TIM4->CNT;
}
