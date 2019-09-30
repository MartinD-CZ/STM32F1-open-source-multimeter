/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "init.h"
#include "delay.h"
#include "sdadc.h"
#include "interrupt.h"
#include "config.h"
#include "draw.h"

int main(void)
{
	init_RCC();
	init_GPIO();
	LED_NONE;
	init_EXTI();
	_delay_init();
	SDADC_init();
	init_TIM3();
	init_BKP();
	init_TIM2();

	drawSplashScreen();								//this function also contains init for UART, EEPROM and ADC1
	_delay_ms(SPLASH_SCREEN_DUR);
	
	SDADC_start();
	
	while (1)
	{
		drawScreen();		
	}
}
