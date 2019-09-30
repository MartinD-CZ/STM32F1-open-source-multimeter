/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "draw.h"
#include "delay.h"
#include "config.h"
#include "adc.h"
#include "ctest.h"
#include "uart.h"
#include "at24c.h"
#include <math.h>

#include "lcd_5110/5110.h"
#include "lcd_5110/fonts/lato_9pt.h"
#include "lcd_5110/fonts/Lato_Heavy_16.h"
#include "lcd_5110/fonts/Lato_Heavy_28.h"
LCD_5110 lcd;

const static char *intro_line1[] = {"VOLTAGE", "CURRENT", "  POWER", "   CONTI", "   COMP", "   FREQU"};
const static char *intro_line2[] = {"   MODE", "   MODE", "   MODE", "   NUITY", "    TEST", "    ENCY"};

volatile uint8_t mode, screen_update;
volatile bool aquisition, hold, rangeI = true;
volatile uint8_t rangeV;

extern volatile uint16_t sdadc_result_samples;
extern volatile float sdadc_result_V_avg, sdadc_result_V_rms, sdadc_result_I_avg, sdadc_result_I_rms;

extern float param;
extern uint8_t cathode, anode;
extern uint8_t partDetected;

extern volatile uint64_t frequency;

extern float param;
extern uint8_t partDetected;

float gainV[4], offsetV[4], gainI[2], offsetI[2];

void drawSplashScreen(void)
{
	adc1_init();
	
	lcd.begin(80, 8);
	lcd.setFont(&Lato_Heavy_16);
	lcd.printxy((char*)"STM32", 14, 14);
	lcd.printxy((char*)"DMM", 20, 29);
	lcd.setFont(&Lato_Medium_9);
	lcd.printxy((char*)"embedblog.eu", 10, 38);
	//lcd.printxy((char*)"M. Danek, 2019", 5, 38);		//TODO
	lcd.printxy((char*)"FW:1.5A", 0, 48);
	lcd.setCursor(44, 48);
	lcd.printf((char*)"B:%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
	lcd.display();
	
	uart_init();
	uart_print((char*)"STM32 Open Source Multimeter\nrevision 1.5    embedblog.eu\n");
	
	at24c_init(0x50);
	uint8_t flag = at24c_read_byte(0);
	
	if (flag == DATA_SAVED)
	{
		for (uint8_t i = 0; i < 4; i ++)
			eeprom_read_floats(8 + 8 * i, gainV[i], offsetV[i]);
		for (uint8_t i = 0; i < 2; i ++)
			eeprom_read_floats(40 + 8 * i, gainI[i], offsetI[i]);
		
		uart_print((char*)"calibration floats loaded from EEPROM\n");
	}
	else
	{
		//TODO: ERROR
		LED_RED;
		uart_print((char*)"could not load calibration floats from EEPROM!\n");
		while(1);
	}
}

void drawScreen(void)
{
	LED_NONE;
	lcd.clearDisplay();
	lcd.setFont(&Lato_Heavy_16);
	lcd.printxy((char*)intro_line1[mode], 0, 20);
	lcd.printxy((char*)intro_line2[mode], 0, 35);
	lcd.display();
	_delay_ms(SCREEN_TRANSISTION_DUR);
	LED_GREEN;
	
	switch (mode)
	{
		case 0: drawVoltScreen(); break;
		case 1:	drawCurrScreen();	break;
		case 2: drawPowerScreen(); break;
		case 3:	drawContScreen();	break;
		case 4: drawCompTestScreen();	break;
		case 5: drawFreqScreen(); break;
	}
}

void drawVoltScreen(void)
{
	while (mode == MODE_VOLTAGE)
	{
		lcd.clearDisplay();
		
		lcd.setFont(&Lato_Heavy_28);
		float display = (aquisition ? sdadc_result_V_avg : sdadc_result_V_rms) * gainV[rangeV] + offsetV[rangeV];
		lcd.setCursor(0, 22);
		
		switch (rangeV)
		{
			case 0:
				lcd.printf((char*)"%6.2f", display);
				//if (display >= 65) BUZZER_ON; else BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"60 V", 35, 31);
				break;
			case 1:
				lcd.printf((char*)"%5.3f", display);
				//if (display >= 6.5) BUZZER_ON; else BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"6 V", 35, 31);
				break;
			case 2:
				lcd.printf((char*)"%5.1f", display);
				BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"600 mV", 20, 31);
				break;
			case 3:
				lcd.printf((char*)"%4.1f", display);
				BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"60 mV", 26, 31);
				break;
			default: break;
		}
		
		lcd.printxy(aquisition ? (char*)"DC" : (char*)"RMS", 60, 31);
		#ifdef RAW_OUTPUT
			lcd.setCursor(0, 48);
			lcd.printf((char*)"RAW: %5.0f", aquisition ? sdadc_result_V_avg : sdadc_result_V_rms);
		#else
			lcd.setCursor(51, 48);
			lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		#endif
		lcd.display();
		
		uart_printf((char*)"%6.3f V\n", display);
		
		while (!screen_update || hold);
		screen_update = false;
	}
}

void drawCurrScreen(void)
{
	while (mode == MODE_CURRENT)
	{
		lcd.clearDisplay();
		
		lcd.setFont(&Lato_Heavy_28);
		float display = (aquisition ? sdadc_result_I_avg : sdadc_result_I_rms) * gainI[rangeI] + offsetI[rangeI];
		if (rangeI)
		{
			lcd.setCursor(0, 22);
			lcd.printf((char*)"%05.1f", display);
			lcd.setFont(&Lato_Medium_9);
			lcd.printxy((char*)"250 mA", 21, 31);
			/*if (display >= 520)
				BUZZER_ON;
			else
				BUZZER_OFF;*/
		}
		else
		{
			lcd.setCursor(0, 22);
			lcd.printf((char*)"%5.3f", display);
			lcd.setFont(&Lato_Medium_9);
			lcd.printxy((char*)"2.5 A", 32, 31);
			/*if (display >= 65)
				BUZZER_ON;
			else
				BUZZER_OFF;*/
		}
		
		lcd.printxy(aquisition ? (char*)" DC" : (char*)"RMS", 60, 31);
		#ifdef RAW_OUTPUT
			lcd.setCursor(0, 48);
			lcd.printf((char*)"RAW: %5.0f", aquisition ? sdadc_result_I_avg : sdadc_result_I_rms);
		#else
			lcd.setCursor(51, 48);
			lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		#endif
		lcd.display();
		
		uart_printf((char*)"%5.3f mA", display);
		
		while (!screen_update || hold);
		screen_update = false;
	}
}

void drawPowerScreen(void)
{
	while (mode == MODE_POWER)
	{
		lcd.clearDisplay();
		
		float volt = (aquisition ? sdadc_result_V_avg : sdadc_result_V_rms) * gainV[rangeV] + offsetV[rangeV];
		float amp = (aquisition ? sdadc_result_I_avg : sdadc_result_I_rms) * gainI[rangeI] + offsetI[rangeI];
		
		lcd.setFont(&Lato_Heavy_28);
		lcd.setCursor(0, 22);
		
		lcd.printf((char*)"%5.2f", abs(volt * amp));
		lcd.setFont(&Lato_Medium_9);
		if ((rangeV < 2) & (!rangeI))
			lcd.printxy(aquisition ? (char*)"W DC" : (char*)"W RMS", 0, 48);
		else if ((rangeV > 1) & rangeI)
			lcd.printxy(aquisition ? (char*)"uW DC" : (char*)"uW RMS", 0, 48);
		else
			lcd.printxy(aquisition ? (char*)"mW DC" : (char*)"mW RMS", 0, 48);

		lcd.setCursor(0, 31);
		if (rangeV < 2)
			lcd.printf((char*)"%5.2f V", volt);
		else
			lcd.printf((char*)"%5.1f mV", volt);
		lcd.setCursor(44, 31);
		switch(rangeV) {case 0: lcd.print((char*)"/60 V"); break; case 1: lcd.print((char*)"/6 V"); break; case 2: lcd.print((char*)"/600 mV"); break; case 3: lcd.print((char*)"/60 mV"); break;};
		
		lcd.setCursor(0, 40);
		lcd.printf((char*)"%4.0f", rangeI ? amp : (amp * 1000));
		lcd.printxy(rangeI ? (char*)"/250 mA" : (char*)"/2500 mA", 30, 40);

		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		
		lcd.display();
		
		uart_printf((char*)"%6.3f V; %5.3 mA; %5.2f W", volt, amp, volt * amp);
		
		while (!screen_update || hold);
		screen_update = false;
	}
}

void drawContScreen(void)
{
	OFSEL_GND;
	TP2L_HIGH; TP2M_HIGHZ; TP2H_HIGHZ;
	
	while (mode == MODE_CONT)
	{
		lcd.clearDisplay();
		
		float volt = adc1_getReading(TP2, 16) * VSUP / 4096;
		
		if (volt > 2.9f) volt = VSUP;
		
		float amp = (VSUP - volt) / (220 + IO_COMPENSATION);
		
		if (amp < 0.0f) amp = 0.0f;
		
		float res = volt / amp;
		
		if (res < CONTINUITY_BUZZER)
			BUZZER_ON;
		else
			BUZZER_OFF;
		
		lcd.setFont(&Lato_Heavy_28);
		lcd.setCursor(0, 22);
		lcd.printf((char*)"%5.0f", res);
		
		lcd.setFont(&Lato_Medium_9);
		lcd.printxy((char*)"OHM", 51, 31);
		/*lcd.setCursor(0, 40);
		lcd.printf("%5.2f mA", amp * 1000);*/
		lcd.setCursor(35, 40);
		lcd.printf((char*)"Uf: %4.2f V", volt);
		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		
		lcd.display();
		
		_delay_ms(1000 / CONTINUITY_REFRESH);
	}
	
	BUZZER_OFF;
	TP2L_HIGHZ;
	OFSEL_VREF2;
}

void drawCompTestScreen(void)
{
	LED_NONE;
	lcd.clearDisplay();
	lcd.setFont(&Lato_Medium_9);
	lcd.printxy((char*)"COMP. TEST", 0, 8);
	lcd.drawLine(0, 10, 96, 10, 1);
	lcd.printxy((char*)"Press 'hold'", 16, 20);
	lcd.printxy((char*)"to start test", 14, 30);
	
	lcd.display();
	
	while (mode == MODE_COMPTEST)
	{
		while ((!hold) & (mode == MODE_COMPTEST));
		hold = false;
		LED_NONE;
		
		partDetected = PART_NONE;
		componentTest();
		
		lcd.clearDisplay();
		
		lcd.printxy((char*)"COMP. TEST", 14, 8);
		lcd.drawLine(0, 10, 96, 10, 1);
		
		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		
		switch(partDetected)
		{
			case PART_RESISTOR:
				lcd.setCursor(15, 20);
				lcd.print((char*)"RESISTOR");
				lcd.setCursor(10, 29);
				lcd.print((char*)"TP1 -==- TP2");
				lcd.setCursor(10, 38);
				lcd.printf((char*)"R = %5.0f Ohm", param);
				break;
			case PART_DIODE:
				lcd.setCursor(20, 20);
				lcd.print((char*)"DIODE");
				lcd.setCursor(15, 29);
				lcd.print((char*)"TP1 ->- TP2");
				lcd.setCursor(10, 38);
				lcd.printf((char*)"Uf = %5.3f V", param);
				break;
			case PART_CAPACITOR:
				lcd.setCursor(10, 20);
				lcd.print((char*)"CAPACITOR");
				lcd.setCursor(11, 29);
				lcd.print((char*)"TP1 -||- TP2");
				lcd.setCursor(9, 38);
				lcd.printf((char*)"C = %6.2f uF", param);
				break;
			default:
				lcd.printxy((char*)"Nothing found", 0, 20);
				break;
		}
		
		lcd.display();
	}
}

void drawFreqScreen(void)
{
	//PA5 to alternative mode as TIM2's ETR
	GPIOA->MODER &=~ GPIO_MODER_MODER5;
	GPIOA->MODER |= GPIO_MODER_MODER5_1;
	GPIOA->AFR[0] |= (1 << 20);
	
	while (mode == MODE_FREQUENCY)
	{
		lcd.clearDisplay();
		lcd.setFont(&Lato_Heavy_28);
		lcd.setCursor(0, 22);
		if (frequency < 100000)
		{
			lcd.printf((char*)"%5d", frequency);
			lcd.setFont(&Lato_Medium_9);
			lcd.printxy((char*)"Hz", 60, 31);
		}
		else
		{
			lcd.printf((char*)"%5d", frequency / 1000);
			lcd.setFont(&Lato_Medium_9);
			lcd.printxy((char*)"kHz", 55, 31);
		}
		
		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc1_getReading(VBAT) * 2 * VSUP / 4096);
		lcd.display();
		
		while (!screen_update);
		screen_update = false;
	}
	
	TP2L_HIGHZ;
}


