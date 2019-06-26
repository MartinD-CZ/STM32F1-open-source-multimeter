//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// this is the 'main' file for the project
// CC BY-NC-SA 4.0 International
// ===================================================

#include "stm32f10x.h"
#include "init.h"
#include "delay.h"
#include "draw.h"
#include "adc.h"
#include "uart.h"
#include "defines.h"
#include "interrupt.h"

extern volatile uint8_t mode;

int main()
{
	init_rcc();
	init_gpio();
	
	_delay_init();
	adc1_init();
	adc2_init();
	init_timer2();
	init_rtc();
	setVoltageRange();
	setCurrentRange();
	
	drawSplashScreen();
	
	LED_ON;
	//BUZZER_ON;
	_delay_ms(200);
	BUZZER_OFF;
	_delay_ms(800);
	LED_OFF;
	
	init_exti();
	adc1_start();
	
	while (1)
	{
		drawScreen();
	}
}
