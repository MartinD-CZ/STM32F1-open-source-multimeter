//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC 4.0
// ===================================================

#include "stm32f3xx.h"
#include "draw.h"
#include "delay.h"
#include "config.h"
//#include "adc.h"
//#include "ctest.h"
#include "uart.h"

#include "lcd_5110/5110.h"
#include "lcd_5110/fonts/lato_9pt.h"
#include "lcd_5110/fonts/Lato_Heavy_16.h"
#include "lcd_5110/fonts/Lato_Heavy_28.h"
LCD_5110 lcd;

const static char *intro_line1[] = {"VOLTAGE", "CURRENT", "  POWER", "   CONTI", "   COMP", "  ABOUT"};
const static char *intro_line2[] = {"   MODE", "   MODE", "   MODE", "   NUITY", "    TEST", ""};

volatile uint8_t mode, screen_update;
volatile bool aquisition, hold, rangeI = true;
volatile uint8_t rangeV;

const static float gainV[4] = {0.00179685383230002, 0.00020376070289328, 0.02661292851990090, 0.00329895192147729};
const static float offsetV[4] = {-0.11050651068644900, -0.00463333146790479, 0.15401938337034100, 2.11392447180170000};
const static float gainI[2] = {0.00001887419809107, 0.00000413386486215};
const static float offsetI[2] = {-0.00301374198091053, -0.00102421359418443};

void drawSplashScreen(void)
{
	lcd.begin(80, 8);
	lcd.setFont(&Lato_Heavy_16);
	lcd.printxy((char*)"STM32", 14, 14);
	lcd.printxy((char*)"DMM v1.5", 0, 29);
	lcd.setFont(&Lato_Medium_9);
	lcd.printxy((char*)"martin@", 22, 38);
	lcd.printxy((char*)"embedblog.eu", 10, 46);
	lcd.display();
	uart_init();
	uart_print((char*)"STM32 multimeter initialized\n");
}

void drawScreen(void)
{
	lcd.clearDisplay();
	lcd.setFont(&Lato_Heavy_16);
	lcd.printxy((char*)intro_line1[mode], 0, 20);
	lcd.printxy((char*)intro_line2[mode], 0, 35);
	lcd.display();
	_delay_ms(SCREEN_TRANSISTION_TIME);
	
	switch (mode)
	{
		case 0: drawVoltScreen(); break;
		case 1:	drawCurrScreen();	break;
		case 2: drawPowerScreen(); break;
		case 3:	drawContScreen();	break;
		case 4: drawCompTestScreen();	break;
		case 5: drawAboutScreen(); break;
	}
}

void drawVoltScreen(void)
{
	while (mode == MODE_VOLTAGE)
	{
		lcd.clearDisplay();
		
		lcd.setFont(&Lato_Heavy_28);
		float display = 0;//(aquisition ? sdadc_result_V_avg : sdadc_result_V_rms) * gainV[rangeV] + offsetV[rangeV];
		lcd.setCursor(0, 22);
		
		switch (rangeV)
		{
			case 0:
				lcd.printf((char*)"%6.2f", display);
				//if (display >= 65) BUZZER_ON; else BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"60 V", 50, 40);
				break;
			case 1:
				lcd.printf((char*)"%5.3f", display);
				//if (display >= 6.5) BUZZER_ON; else BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"6 V", 55, 40);
				break;
			case 2:
				lcd.printf((char*)"%5.1f", display);
				BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"600 mV", 40, 40);
				break;
			case 3:
				lcd.printf((char*)"%5.2f", display);
				BUZZER_OFF;
				lcd.setFont(&Lato_Medium_9);
				lcd.printxy((char*)"60 mV", 45, 40);
				break;
			default: break;
		}
		
		lcd.printxy(aquisition ? (char*)"DC" : (char*)"RMS", 60, 31);
		lcd.setCursor(0, 48);
		//lcd.printf((char*)"RAW: %5.0f", aquisition ? sdadc_result_V_avg : sdadc_result_V_rms);
		lcd.setCursor(51, 48);
		//lcd.printf((char*)"%4.2f V", adc2_getReading(VBAT) * 2 * (adc1_result_vsup / 4096.0));
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
		float display = 0;//(aquisition ? sdadc_result_I_avg : sdadc_result_I_rms) * gainI[rangeI] + offsetI[rangeI];
		if (rangeI)
		{
			lcd.setCursor(0, 22);
			//lcd.printf((char*)"%03.0f", display);
			lcd.printf((char*)"%5.3f", display);
			/*if (display >= 520)
				BUZZER_ON;
			else*/
				BUZZER_OFF;
		}
		else
		{
			lcd.setCursor(0, 22);
			//lcd.printf((char*)"%04.1f", display);
			lcd.printf((char*)"%5.3f", display);
			/*if (display >= 65)
				BUZZER_ON;
			else*/
				BUZZER_OFF;
		}
		
		lcd.setFont(&Lato_Medium_9);
		lcd.printxy(aquisition ? (char*)"mA DC" : (char*)"mA RMS", 44, 31);
		lcd.printxy(rangeI ? (char*)"60 mA" : (char*)"0.6 A", 46, 40);
		lcd.setCursor(0, 48);
		//lcd.printf((char*)"RAW: %5.0f", aquisition ? sdadc_result_I_avg : sdadc_result_I_rms);
		//lcd.printf((char*)"%4.2f V", adc1_result_vsup);
		//lcd.setCursor(51, 48);
		//lcd.printf((char*)"%4.2f V", adc2_getReading(VBAT) * 2 * (adc1_result_vsup / 4096.0));
		
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
		
		float volt = 0;//aquisition ? sdadc_result_V_avg : sdadc_result_V_rms;
		float amp = 0;//aquisition ? sdadc_result_I_avg : sdadc_result_I_rms;
		
		lcd.setFont(&Lato_Heavy_28);
		lcd.setCursor(0, 22);
		lcd.printf((char*)"%05.2f", volt * amp);

		lcd.setFont(&Lato_Medium_9);
		lcd.setCursor(0, 31);
		lcd.printf((char*)"%6.2f V", volt);
		lcd.setCursor(0, 40);
		lcd.printf((char*)"%5.3f A", amp);
		
		lcd.printxy(aquisition ? (char*)"W DC" : (char*)"W RMS", 48, 31);
		lcd.printxy(rangeV ? (char*)"60/" : (char*)"6/", 48, 40);
		lcd.printxy(rangeI ? (char*)".5" : (char*)"60m", 64, 40);
		lcd.setCursor(0, 48);
		//lcd.printf((char*)"%4.2f V", adc1_result_vsup);
		lcd.setCursor(51, 48);
		//lcd.printf((char*)"%4.2f V", adc2_getReading(VBAT) * 2 * (adc1_result_vsup / 4096.0));
		
		lcd.display();
		
		uart_printf((char*)"%6.3f V; %5.3 mA; %5.2f W", volt, amp, volt * amp);
		
		while (!screen_update || hold);
		screen_update = false;
	}
}

void drawContScreen(void)
{
	//PA9_LOW; PB2_HIGH; PA7_ANALOG;
	
/*	while (mode == MODE_CONT)
	{
		lcd.clearDisplay();
		
		//float volt = adc2_getReading(TP3, 8) * (adc1_result_vsup / 4096.0);
		if (volt < 0.007)
			volt = 0;
		else		
			volt += 0.05;
		
		float amp = volt / 680.0;
		float res = (1.25 - volt) / amp;
		
		if (res < 50)
			BUZZER_ON;
		else
			BUZZER_OFF;
		
		if (res < 0) res = 0;
		
		lcd.setFont(&Lato_Heavy_28);
		lcd.setCursor(0, 22);
		lcd.printf((char*)"%05.0f", res);
		
		lcd.setFont(&Lato_Medium_9);
		lcd.printxy("OHM", 51, 31);
		lcd.setCursor(51, 40);
		lcd.printf("%4.2f V", 1.25 - volt);
		lcd.setCursor(0, 48);
		lcd.printf((char*)"%4.2f V", adc1_result_vsup);
		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc2_getReading(VBAT) * 2 * (adc1_result_vsup / 4096.0));
		
		lcd.display();
		
		_delay_ms(1000 / CONTINUITY_REFRESH);
	}
	
	BUZZER_OFF;
	PA9_HIGHZ;*/
}

void drawCompTestScreen(void)
{
	/*LED_OFF;
	lcd.clearDisplay();
	lcd.setFont(&Lato_Medium_9);
	lcd.printxy("COMP. TEST", 0, 8);
	lcd.drawLine(0, 10, 96, 10, 1);
	lcd.printxy("Press 'hold'", 16, 20);
	lcd.printxy("to start test", 14, 30);
	
	lcd.display();
	
	while (mode == MODE_COMPTEST)
	{
		while ((!hold) & (mode == MODE_COMPTEST));
		hold = false;
		
		partDetected = PART_NONE;
		testPins(TP1, TP2);
		LED_ON;
		
		lcd.clearDisplay();
		
		lcd.printxy("COMP. TEST", 0, 8);
		lcd.drawLine(0, 10, 96, 10, 1);
		
		lcd.setCursor(0, 48);
		lcd.printf((char*)"%4.2f V", adc1_result_vsup);
		lcd.setCursor(51, 48);
		lcd.printf((char*)"%4.2f V", adc2_getReading(VBAT) * 2 * (adc1_result_vsup / 4096.0));
		
		
		switch(partDetected)
		{
			case PART_RESISTOR:
				lcd.setCursor(15, 20);
				lcd.print("RESISTOR");
				lcd.setCursor(20, 29);
				lcd.printf("%d -==- %d", cathode, anode);
				lcd.setCursor(10, 38);
				lcd.printf("R = %5.0f Ohm", param);
				break;
			case PART_DIODE:
				lcd.setCursor(20, 20);
				lcd.print("DIODE");
				lcd.setCursor(20, 29);
				lcd.printf("%d ->- %d", anode, cathode);
				lcd.setCursor(10, 38);
				lcd.printf("Uf = %5.3f V", param);
				break;
			case PART_CAPACITOR:
				lcd.setCursor(10, 20);
				lcd.print("CAPACITOR");
				lcd.setCursor(20, 29);
				lcd.printf("%d -| |- %d", anode, cathode);
				lcd.setCursor(10, 38);
				lcd.printf("C = %6.2f uF", param);
				break;
			default:
				lcd.printxy("Nothing found", 0, 20);
				break;
		}
		
		lcd.display();
	}*/
}

void drawAboutScreen(void)
{
	//LED_OFF;
	while (mode == MODE_ABOUT)
	{
		lcd.clearDisplay();
		lcd.setFont(&Lato_Heavy_16);
		lcd.printxy((char*)"STM32", 14, 14);
		lcd.printxy((char*)"DMM v1.4", 0, 29);
		lcd.setFont(&Lato_Medium_9);
		lcd.printxy((char*)"martin@", 22, 38);
		lcd.printxy((char*)"embedblog.eu", 10, 46);
		lcd.display();
		
		while (!screen_update);
		screen_update = false;
	}
}


