/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "init.h"
#include "config.h"
#include "interrupt.h"

extern volatile uint8_t mode, rangeV;
extern volatile bool rangeI, aquisition;

void init_RCC(void)
{
	//init RCC to external crystal, PLL x9;
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_PLLMUL9 | RCC_CFGR_PPRE1_DIV2;
	RCC->CR |= RCC_CR_HSEON | RCC_CR_PLLON;
	FLASH->ACR |= FLASH_ACR_LATENCY_1;
	
	while (!(RCC->CR & RCC_CR_PLLRDY));
	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
}

void init_GPIO(void)
{
	//enable GPIO clocks
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOCEN | RCC_AHBENR_GPIODEN | RCC_AHBENR_GPIOEEN| RCC_AHBENR_GPIOFEN;
	
	//enable OFSEL on PA12
	GPIOA->MODER |= GPIO_MODER_MODER12_0;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12;
	
	//enable buzzer on PA8
	GPIOA->MODER |= GPIO_MODER_MODER8_0;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;
	
	//enable VSEL on PF6:7
	GPIOF->MODER |= GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0;
	GPIOF->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
	
	//enable ISEL on PB2
	GPIOB->MODER |= GPIO_MODER_MODER2_0;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;
	
	//enable LED on PB6:7
	GPIOB->MODER |= GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
	
	//se PA3:6, PB14:15 to high speed (used later for component testing/continuity)
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR6;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14 | GPIO_OSPEEDER_OSPEEDR15;
}

void init_EXTI(void)
{
	//button pins (PC13:15, PA11) - inputs with pullups
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR13_0 | GPIO_PUPDR_PUPDR14_0 | GPIO_PUPDR_PUPDR15_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR11_0;

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI11_PA;
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC | SYSCFG_EXTICR4_EXTI14_PC | SYSCFG_EXTICR4_EXTI15_PC;
	
	EXTI->IMR |= EXTI_IMR_MR11 | EXTI_IMR_MR13 | EXTI_IMR_MR14 | EXTI_IMR_MR15;
	EXTI->FTSR |= EXTI_FTSR_TR11 | EXTI_FTSR_TR13 | EXTI_FTSR_TR14 | EXTI_FTSR_TR15;
	
	NVIC_SetPriority(EXTI15_10_IRQn, 7);
	
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_TIM3(void)			//used to update data
{
	//enable clock to Timer 3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	//set prescaler (7.2k - 1)
	TIM3->PSC = 7199;
	
	//set auto-reload register
	TIM3->ARR = (10000/SCREEN_UPDATE_RATE);
	
	//update registers
	TIM3->EGR |= TIM_EGR_UG;
	
	//zero the counter
	TIM3->CNT = 0x00;
	
	//enable interrupt on timer overflow (aka update event)
	TIM3->DIER |= TIM_DIER_UIE;
	
	NVIC_SetPriority(TIM3_IRQn, 1);
	NVIC_EnableIRQ(TIM3_IRQn);
	
	//enable timer
	TIM3->CR1 |= TIM_CR1_CEN;
}

void init_BKP(void)
{
	//disable write protection
	PWR->CR |= PWR_CR_DBP;
	
	if (RTC->BKP0R == DATA_SAVED)
	{
		mode = RTC->BKP1R;
		rangeV = RTC->BKP2R;
		rangeI = RTC->BKP3R;
		aquisition = RTC->BKP4R;
	}
	else
	{
		RTC->BKP0R = DATA_SAVED;
	}
	
	setVoltageRange();
	setCurrentRange();
	
	OFSEL_VREF2;
}

void init_TIM2(void)
{
	//enable clock to Timer 2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	//write into SMCR - prescaler /1; no filter; rising edge; clock mode 2
	TIM2->SMCR = TIM_SMCR_ECE;
	
	//enable counter
	TIM2->CR1 |= TIM_CR1_CEN;
}

