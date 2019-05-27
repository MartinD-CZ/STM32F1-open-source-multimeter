//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "init.h"
#include "delay.h"
#include "draw.h"
#include "adc.h"
#include "uart.h"
#include "defines.h"

extern volatile uint8_t mode;

int main()
{
	init_rcc();
	init_gpio();
	RANGE_60V;
	RANGE_500mA;
	_delay_init();
	adc1_init();
	adc2_init();
	init_timer2();
	mode = init_rtc();
	
	drawSplashScreen();
	
	LED_RED;
	BUZZER_ON;
	_delay_ms(200);
	BUZZER_OFF;
	LED_GREEN;
	_delay_ms(800);
	LED_OFF;
	
	init_exti();
	adc1_start();
	
	while (1)
	{
		drawScreen();
	}
}
