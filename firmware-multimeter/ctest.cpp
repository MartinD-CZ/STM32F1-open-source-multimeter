/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "config.h"
#include "ctest.h"
#include "delay.h"
#include "adc.h"
#include "uart.h"
#include <math.h>

float param;
uint8_t cathode, anode;
uint8_t partDetected;

void componentTest()
{
	uart_print((char*)"COMPONENT TEST STARTED\n");
	
	//first, we determine the supply voltage
	float vsup = 4096 * VREF / (2 * adc1_getReading(REF, 32));
	uart_printf((char*)"Supply voltage: %4.2f V\n", vsup);
	
	//then we discharge both sides to make sure there is no charge left
	TP1L_LOW;
	TP1M_HIGHZ;
	TP1H_HIGHZ;
	TP1A_ANALOG;
	
	TP2L_LOW;
	TP2M_HIGHZ;
	TP2H_HIGHZ;
	TP2A_ANALOG;
	
	_delay_ms(100);
	
	TP1L_HIGHZ;
	TP2L_HIGHZ;
	//connect side 1 to ground and charge side 2 thru a 2k2 resistor
	TP1A_LOW;
	TP2M_HIGH;
	
	_delay_ms(100);
	
	//now we will put TP2 into high impedance, wait a short while and then decide if its a resistor or something with some energy storage (capacitor)
	TP2M_HIGHZ;
	
	_delay_us(1000);
	
	uint16_t volt = adc1_getReading(TP2, 16);
	
	uart_printf((char*)"Voltage on TP2: %4d ADC ->", volt);
	
	if (volt > 500)		//there's some voltage left, so we are assuming a capacitor
	{
		uart_print((char*)" LC\n");
		//first, we measure tau (time constant RC) - again, first discharge the device
		TP2L_LOW;
		
		_delay_ms(100);
		
		TP2L_HIGHZ;
		TP2A_LOW;
		
		//now start charging
		TP2A_ANALOG;
		TP2M_HIGH;
		_count_us_start();
		
		//wait for voltage to rise
		while (adc1_getReading(TP2, 1) < 2580);
		
		uint16_t tau = _count_us_stop();
		uart_printf((char*)"time constant: %5d us\n", tau);
		float capacity = tau / 2200.0f;
		uart_printf((char*)"Capacitor with a capacity of %6.2f uF\n", capacity);
	
		partDetected = PART_CAPACITOR;
		param = capacity;
	}		
	else							//the voltage collapsed very fast, so it must be a diode, a resistor or nothing
	{
		uart_print((char*)" RD\n");
		
		//now we need to decide if it is a diode or a resistor - we simply measure resistance both ways
		float rAB, rBA, vAB, vBA, temp;
		TP2M_HIGH;
		
		vAB = adc1_getReading(TP2, 16) * (vsup / 4096);
		rAB = (2200 * vAB) / (vsup - vAB);
		uart_printf((char*)"voltage on pin TP2: %5.3f V\n", vAB);
		uart_printf((char*)"resistance rAB: %5.0f Ohm\n", rAB);
		
		TP2A_LOW;
		TP1A_ANALOG;
		TP2M_HIGHZ;
		TP1M_HIGH;
		
		vBA = adc1_getReading(TP1, 16) * (vsup / 4096);
		rBA = (2200 * vBA) / (vsup - vBA);
		uart_printf((char*)"voltage on pin TP1: %5.3f V\n", vBA);
		uart_printf((char*)"resistance rBA: %5.0f Ohm\n", rBA);
		
		temp = (rAB + rBA) / 2;
		if ((vAB > 2.4f) & (vBA > 2.4f))
		{
			//nothing
			uart_print((char*)"No connection between pins\n");
		}
		else if (abs(rAB - rBA) < (temp * 0.25f))
		{
			//resistances are less different than 25 % - it's a resistor!
			uart_printf((char*)"Resistor with a resistance of %5.0f Ohm\n", temp);
			partDetected = PART_RESISTOR;
			param = temp;
			//TODO: in case of a high resistance (> 50k) do the test again with the 470k resistors
		}
		else
		{
			//so it is a diode
			uart_printf((char*)"Diode with a forward voltage drop of %5.3f V\n", vAB > vBA ? vBA : vAB);
			partDetected = PART_DIODE;
			param = vAB > vBA ? vBA : vAB;
			/*cathode = vAB > vBA ? pinB : pinA;
			anode = vAB > vBA ? pinA : pinB;*/
		}
	}
	
	uart_print((char*)"TEST FINISHED\n");
	TP1M_HIGHZ;
	TP1A_ANALOG;
	TP2A_ANALOG;
}
