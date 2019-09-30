/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "init.h"
#include "delay.h"
#include "config.h"
#include "uart.h"
#include "at24c.h"

#include "lcd_5110/5110.h"
#include "lcd_5110/fonts/lato_9pt.h"
#include "lcd_5110/fonts/Lato_Heavy_16.h"
#include "lcd_5110/fonts/Lato_Heavy_28.h"
LCD_5110 lcd;

#define DATA_SAVED		0xC0

uint8_t calibration_day = 21, calibration_month = 9, calibration_year = 19, calibration_temperature = 20;

/*float gainV[4] = {0.00179685383230002, 0.00020376070289328, 0.02661292851990090, 0.00329895192147729};
float offsetV[4] = {-0.11050651068644900, -0.00463333146790479, 0.15401938337034100, 2.11392447180170000};
float gainI[2] = {0.00001887419809107, 0.00000413386486215};
float offsetI[2] = {-0.00301374198091053, -0.00102421359418443};*/

/*float gainV[4] = {0.00179558550639711, 0.00020388615216201, 0.02659555023843940, 0.00330470588235294};
float offsetV[4] = {0.08580134778786430, 0.02470935960591180, -4.37169466460630000, -6.01810588235295000};
float gainI[2] = {0.00009859652019566, 0.00941860465116279};
float offsetI[2] = {-0.01055825266764380, -0.72674418604651300};*/

float gainV[4] = {0.00179558550639711, 0.00020388615216201, 0.02659555023843940, 0.00330470588235294};
float offsetV[4] = {0.08580134778786430, -0.00470935960591180, -6.32169466460630000, -8.01810588235295000};
float gainI[2] = {0.00009859652019566, 0.00941860465116279};
float offsetI[2] = {-0.01055825266764380, -0.72674418604651300};

int main(void)
{
	init_RCC();
	init_GPIO();
	LED_NONE;
	_delay_init();
	lcd.begin(80, 8);
	lcd.clearDisplay();
	lcd.setFont(&Lato_Heavy_16);
	lcd.printxy((char*)"EEPROM", 6, 14);
	lcd.printxy((char*)"WRITER", 9, 29);
	lcd.display();
	
	at24c_init(0x50);
	
	for (uint8_t i = 0; i < 4; i ++)
			eeprom_save_floats(8 + 8 * i, gainV[i], offsetV[i]);
	for (uint8_t i = 0; i < 2; i ++)
			eeprom_save_floats(40 + 8 * i, gainI[i], offsetI[i]);
	
	at24c_write_byte(0, DATA_SAVED);
	at24c_write_byte(1, calibration_day);
	at24c_write_byte(2, calibration_month);
	at24c_write_byte(3, calibration_year);
	at24c_write_byte(4, calibration_temperature);
	
	_delay_ms(1000);
	
	uint8_t check = at24c_read_byte(0);
	
	if (check == DATA_SAVED)
	{
		LED_GREEN;
		lcd.printxy((char*)"DONE", 16, 44);
	}
	else
	{
		LED_RED;
		lcd.printxy((char*)"ERROR", 11, 44);
	}
	lcd.display();
	
	while (1)
	{
		
	}
}
