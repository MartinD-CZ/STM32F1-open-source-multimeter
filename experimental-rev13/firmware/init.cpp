//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// most of the init routines (except ADC-related ones) are located here
// CC BY-NC-SA 4.0 International
// ===================================================

#include "stm32f10x.h"
#include "init.h"
#include "defines.h"

extern volatile uint8_t mode, rangeV;
extern volatile bool rangeI;

void init_rcc(void)
{
	//Init the clock system - running from external 8 MHz crystal
	/*RCC->CFGR |= RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9 | RCC_CFGR_PPRE1_DIV2;
	RCC->CR |= RCC_CR_PLLON | RCC_CR_HSEON;
	RCC->CFGR |= RCC_CFGR_SW_PLL;*/
	
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PLLMULL16 | RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PPRE1_DIV2;
	RCC->CR |= RCC_CR_PLLON;
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	
	//set flash latency
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
}

void init_gpio(void)
{
	//enable GPIO clocks
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN;
	
	//enable AFIO and disable JTAG
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->MAPR = (0x2 << 24);
	
	//enable LED on PA3
	GPIOA->CRL |= GPIO_CRL_MODE3;
	GPIOA->CRL &=~GPIO_CRL_CNF3_0;
	
	//enable buzzer on PA12
	GPIOA->CRH |= GPIO_CRH_MODE12;
	GPIOA->CRH &=~GPIO_CRH_CNF12_0;
	
	//enable VSEL on PC13:14
	GPIOC->CRH |= GPIO_CRH_MODE13 | GPIO_CRH_MODE14;
	GPIOC->CRH &=~GPIO_CRH_CNF13_0 | GPIO_CRH_CNF14_0;
	
	//enable ISEL on PA4
	GPIOA->CRL |= GPIO_CRL_MODE4;
	GPIOA->CRL &=~GPIO_CRL_CNF4_0;
}

void init_exti(void)
{
	//button pins (PA8, PB1, PB14, PB15) - inputs with pullups
	GPIOA->CRH &=~ GPIO_CRH_CNF8_0;
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->ODR |= GPIO_ODR_ODR8;
	
	GPIOB->CRL &=~ GPIO_CRL_CNF1_0;
	GPIOB->CRL |= GPIO_CRL_CNF1_1;
	GPIOB->ODR |= GPIO_ODR_ODR1;
	
	GPIOB->CRH &=~ GPIO_CRH_CNF14_0;
	GPIOB->CRH |= GPIO_CRH_CNF14_1;
	GPIOB->ODR |= GPIO_ODR_ODR14;
	
	GPIOB->CRH &=~ GPIO_CRH_CNF15_0;
	GPIOB->CRH |= GPIO_CRH_CNF15_1;
	GPIOB->ODR |= GPIO_ODR_ODR15;
	
	//reset MODE
	//GPIOC->CRH &=~(GPIO_CRH_MODE13_0 | GPIO_CRH_MODE14_0 | GPIO_CRH_MODE15_0);
	
	AFIO->EXTICR[2] |= AFIO_EXTICR3_EXTI8_PA;
	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI1_PB;
	AFIO->EXTICR[3] |= AFIO_EXTICR4_EXTI14_PB | AFIO_EXTICR4_EXTI15_PB;
	
	EXTI->IMR |= EXTI_IMR_MR1 | EXTI_IMR_MR8 | EXTI_IMR_MR14 | EXTI_IMR_MR15;
	EXTI->FTSR |= EXTI_FTSR_TR1 | EXTI_FTSR_TR8 | EXTI_FTSR_TR14 | EXTI_FTSR_TR15;
	
	//NVIC_SetPriorityGrouping(3);
	
	NVIC_SetPriority(EXTI1_IRQn, 7);
	NVIC_SetPriority(EXTI9_5_IRQn, 7);
	NVIC_SetPriority(EXTI15_10_IRQn, 7);
	
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_rtc(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_BKPEN | RCC_APB1ENR_PWREN;
	
	PWR->CR |= PWR_CR_DBP;
	
	if (BKP->DR1 == DATA_SAVED)
	{
		mode = BKP->DR2;
		rangeV = BKP->DR3;
		rangeI = BKP->DR4;
	}
	else
	{
		BKP->DR1 = DATA_SAVED;
	}
}

void init_timer2(void)
{
	//enable clock to Timer 2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	//set prescaler (63k + 1)
	TIM2->PSC = 7199;
	
	//update registers
	TIM2->EGR |= TIM_EGR_UG;
	
	//zero the counter
	TIM2->CNT = 0x00;
	
	//enable interrupt on CC1
	TIM2->DIER |= TIM_DIER_CC1IE;
	
	TIM2->CCR1 = (10000/SCREEN_UPDATE_RATE);
	
	NVIC_SetPriority(TIM2_IRQn, 1);
	NVIC_EnableIRQ(TIM2_IRQn);
	
	//enable timer
	TIM2->CR1 |= TIM_CR1_CEN;
}
