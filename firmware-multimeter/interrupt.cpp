/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "interrupt.h"
#include "config.h"
#include "uart.h"
#include "delay.h"

extern volatile bool aquisition, hold, rangeI;
extern volatile uint8_t mode, screen_update;
extern volatile uint8_t rangeV;

extern "C"
{
	void EXTI15_10_IRQHandler(void)
	{
		if ((EXTI->PR & EXTI_PR_PR11) != 0)			//PA11 - button 'mode'
		{
			mode++;
			screen_update = true;
				
			if (mode >= MODES)
				mode = 0;
				
			RTC->BKP1R = mode;
			EXTI->PR |= EXTI_PR_PR11;
		}
		
		if ((EXTI->PR & EXTI_PR_PR13) != 0)			//PC13 - button 'hold/stop'
		{
			hold = !hold;
			
			if (hold)
				LED_RED;
			else
				LED_GREEN;
			
			EXTI->PR |= EXTI_PR_PR13;
		}
		
		if ((EXTI->PR & EXTI_PR_PR14) != 0)			//PC12 - button 'range'
		{
				if (mode == MODE_VOLTAGE)
				{
					rangeV++;
				
					if (rangeV > 3) rangeV = 0;
					
					setVoltageRange();
					
					RTC->BKP2R = rangeV;
				}
				else if (mode == MODE_CURRENT)
				{
					rangeI = !rangeI;
				
					setCurrentRange();
					
					RTC->BKP3R = rangeI;
				}
			
			EXTI->PR |= EXTI_PR_PR14;
		}
		
		if ((EXTI->PR & EXTI_PR_PR15) != 0)			//PC11 - button 'DC/RMS'
		{
			aquisition = !aquisition;
	
			RTC->BKP4R = aquisition;
			EXTI->PR |= EXTI_PR_PR15;
		}
	}
}

void setVoltageRange(void)
{
	switch (rangeV)
	{
		case 0:			//60 V range
			VSEL0_LOW;
			VSEL1_LOW;
			SDADC2->CR2 &=~SDADC_CR2_ADON;
			SDADC2->CONFCHR2 = 0x00;
			SDADC2->CR2 |= SDADC_CR2_ADON;
			_delay_us(150);
			SDADC2->CR2 |= SDADC_CR2_RSWSTART;
			break;
		case 1:			//6 V range
			VSEL0_HIGH;
			VSEL1_LOW;
			break;
		case 2:			//600 mV range
			VSEL0_LOW;
			VSEL1_HIGH;
			break;
		case 3:			//60 mV range
			VSEL0_LOW;
			VSEL1_HIGH;
			SDADC2->CR2 &=~SDADC_CR2_ADON;
			SDADC2->CONFCHR2 = 0x01;
			SDADC2->CR2 |= SDADC_CR2_ADON;
			_delay_us(150);
			SDADC2->CR2 |= SDADC_CR2_RSWSTART;
			break;
		default: break;
	}
}

void setCurrentRange(void)
{
	if (rangeI)
		ISEL_HIGH;
	else
		ISEL_LOW;
}
