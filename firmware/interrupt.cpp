//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "interrupt.h"
#include "defines.h"

extern volatile bool aquisition, hold, rangeV, rangeI;
extern volatile uint8_t mode, screen_update;

extern "C"
{
	//PB1 - button 'hold/stop'
	void EXTI1_IRQHandler(void)
	{
		if ((EXTI->PR & EXTI_PR_PR1) != 0)
		{
			if ((GPIOB->IDR & GPIO_IDR_IDR1) == 0)
			{
				hold = !hold;
				
				if (hold)
					LED_RED;
				else
					LED_GREEN;
			}
		}
		
		//EXTI->PR = EXTI_PR_PR1;
		EXTI->PR = 0x3FFFF;
	}
	
	//PA8 - button 'mode'
	void EXTI9_5_IRQHandler(void)
	{
		if ((EXTI->PR & EXTI_PR_PR8) != 0)
		{
			if ((GPIOA->IDR & GPIO_IDR_IDR8) == 0)
			{
				mode++;
				screen_update = true;
				
				if (mode >= MODES)
					mode = 0;
				
				BKP->DR2 = mode;
			}
		}
		
		//EXTI->PR = EXTI_PR_PR8;
		EXTI->PR = 0x3FFFF;
	}
	
	void EXTI15_10_IRQHandler(void)
	{
		//PB14 - button 'AVG/RMS'
		if ((EXTI->PR & EXTI_PR_PR14) != 0)
		{
			if ((GPIOB->IDR & GPIO_IDR_IDR14) == 0)
			{
				aquisition = !aquisition;
			}

		}
		
		//PB15 - button 'range'
		else if ((EXTI->PR & EXTI_PR_PR15) != 0)
		{
			if ((GPIOB->IDR & GPIO_IDR_IDR15) == 0)
			{
				if (mode == MODE_VOLTAGE)
				{
					rangeV = !rangeV;
				
					if (rangeV)
						RANGE_60V;
					else
						RANGE_6V;
				}
				else if (mode == MODE_CURRENT)
				{
					rangeI = !rangeI;
				
					if (rangeI)
						RANGE_500mA;
					else
						RANGE_60mA;
				}
				else if (mode == MODE_POWER)
				{
					if (rangeV == false & rangeI == false)
					{
						rangeV = true;
						RANGE_60V;
					}
					else if (rangeV == true & rangeI == false)
					{
						rangeV = false;
						RANGE_6V;
						rangeI = true;
						RANGE_500mA;
					}
					else if (rangeV == false & rangeI == true)
					{
						rangeV = true;
						RANGE_60V;
					}
					else
					{
						rangeV = false;
						RANGE_6V;
						rangeI = false;
						RANGE_60mA;
					}
				}
			}
		}
		
		//EXTI->PR = EXTI_PR_PR15;
		EXTI->PR = 0x3FFFF;
	}
}
