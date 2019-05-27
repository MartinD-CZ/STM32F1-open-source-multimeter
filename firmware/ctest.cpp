//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "defines.h"
#include "ctest.h"
#include "delay.h"
#include "adc.h"
#include "uart.h"
#include <math.h>

extern volatile float adc1_result_vsup;

float param;
uint8_t cathode, anode;
uint8_t partDetected;

void testPins(uint8_t pinA, uint8_t pinB)
{
	if (partDetected != 0)
		return;
	
	uart_print((char*)"COMPONENT TEST STARTED\n");
	
	PB13_HIGHZ;
	PB12_HIGHZ;
	PB2_HIGHZ;
	
	//first, we discharge both pins to make sure there is no charge left
	switch(pinA)
	{
		case TP1: PA11_LOW; break;
		case TP2: PA10_LOW; break;
		case TP3: PA9_LOW; break;
	}
	switch(pinB)
	{
		case TP1: PA11_LOW; break;
		case TP2: PA10_LOW; break;
		case TP3: PA9_LOW; break;
	}
	
	_delay_ms(50);
	
	//now connect both sides to ground
	switch(pinA)
	{
		case TP1: PA5_LOW; break;
		case TP2: PA6_LOW; break;
		case TP3: PA7_LOW; break;
	}
	switch(pinB)
	{
		case TP1: PA5_LOW; break;
		case TP2: PA6_LOW; break;
		case TP3: PA7_LOW; break;
	}
	
	_delay_ms(50);
	
	//then, lets charge the DUT using pinB thru 680 ohm resistor
	switch(pinB)
	{
		case TP1: PA5_ANALOG; PA11_HIGH; break;
		case TP2: PA6_ANALOG; PA10_HIGH; break;
		case TP3: PA7_ANALOG; PA9_HIGH; break;
	}
	
	_delay_ms(50);
	
	//now we will put pinB into high impedance, wait a short while and then decide if its a resistor or something with some energy storage (capacitor or inductor)
	switch(pinB)
	{
		case TP1: PA11_HIGHZ; break;
		case TP2: PA10_HIGHZ; break;
		case TP3: PA9_HIGHZ; break;
	}
	
	_delay_us(1000);
	
	uint16_t volt = adc2_getReading(pinB);
	
	uart_printf((char*)"Voltage on pin TP%d: %4d DAC ->", pinB, volt);
	
	if (volt > 500)		
		goto C;					//there's some voltage left, so we are assuming either a diode or a capacitor
	else
		goto RD;				//the voltage collapsed very fast, so it must be a diode, a resistor or nothing
	
	C:
	//uart_print(" LC\n");
	//first, we measure tau (time constant RC) - again, first discharge the device
	switch(pinA)
	{
		case TP1: PA11_LOW; break;
		case TP2: PA10_LOW; break;
		case TP3: PA9_LOW; break;
	}
	switch(pinB)
	{
		case TP1: PA11_LOW; break;
		case TP2: PA10_LOW; break;
		case TP3: PA9_LOW; break;
	}
	_delay_ms(50);
	
	//now start charging
	switch(pinA)
	{
		case TP1: PA5_LOW; break;
		case TP2: PA6_LOW; break;
		case TP3: PA7_LOW; break;
	}
	switch(pinB)
	{
		case TP1: PA5_ANALOG; PA11_HIGH; break;
		case TP2: PA6_ANALOG; PA10_HIGH; break;
		case TP3: PA7_ANALOG; PA9_HIGH; break;
	}
	_count_us_start();
	
	while (adc2_getReading(pinB, 1) < 2580);
		
	uint16_t tau = _count_us_stop();
	//uart_printf("time constant: %5d s\n", tau);
	float capacity = tau / 680.0;
	uart_printf("Capacitor with a capacity of %6.2f uF\n", capacity);
	
	partDetected = PART_CAPACITOR;
	param = capacity;
	cathode = pinA;
	anode = pinB;
	
	goto endTest;
	
	RD:
	//uart_print(" RD\n");
	//now we need to decide if it is a diode or a resistor - we simply measure resistance both ways
	float rAB, rBA, vAB, vBA, temp;
	
	//making a divider with a 680 ohm resistor
	switch(pinB)
	{
		case TP1: PA11_HIGH; break;
		case TP2: PA10_HIGH; break;
		case TP3: PA9_HIGH; break;
	}
	
	vAB = adc2_getReading(pinB, 16) * (adc1_result_vsup / 4096.0);
	//uart_printf("voltage on pin TP%d: %5.3f V\n", pinB, vAB);
	rAB = (680 * vAB) / (adc1_result_vsup - vAB);
	//uart_printf("resistance rAB: %5.0f Ohm\n", rAB);
	
	//now lets switch sides - pinA will be high thru 680 ohms and pinB will be ground
	switch(pinA)
	{
		case TP1: PA5_ANALOG; PA11_HIGH; break;
		case TP2: PA6_ANALOG; PA10_HIGH; break;
		case TP3: PA7_ANALOG; PA9_HIGH; break;
	}
	switch(pinB)
	{
		case TP1: PA11_HIGHZ; PA5_LOW; break;
		case TP2: PA10_HIGHZ; PA6_LOW; break;
		case TP3: PA9_HIGHZ; PA7_LOW; break;
	}
	
	vBA = adc2_getReading(pinA, 16) * (adc1_result_vsup / 4096.0);
	//uart_printf("voltage on pin TP%d: %5.3f V\n", pinA, vBA);
	rBA = (680 * vBA) / (adc1_result_vsup - vBA);
	//uart_printf("resistance rBA: %5.0f Ohm\n", rBA);
	
	temp = (rAB + rBA) / 2;
	if ((vAB > 2.4) & (vBA > 2.4))
	{
		//nothing
		//uart_print("No connection between pins\n");
	}
	else if (abs(rAB - rBA) < (temp * 0.25))
	{
		//resistances are less different than 25 % - it's a resistor!
		uart_printf((char*)"Resistor with a resistance of %5.0f Ohm\n", temp);
		partDetected = PART_RESISTOR;
		param = temp;
		cathode = pinA;
		anode = pinB;
		//TODO: in case of a high resistance (> 50k) do the test again with the 470k resistors
	}
	else
	{
		//so it is a diode
		uart_printf((char*)"Diode with a forward voltage drop of %5.3f V\n", vAB > vBA ? vBA : vAB);
		partDetected = PART_DIODE;
		param = vAB > vBA ? vBA : vAB;
		cathode = vAB > vBA ? pinB : pinA;
		anode = vAB > vBA ? pinA : pinB;
	}
	
	
	endTest:
	uart_print((char*)"TEST FINISHED\n");
	PA11_HIGHZ;
	PA10_HIGHZ;
	PA9_HIGHZ;
	PA5_ANALOG;
	PA6_ANALOG;
	PA7_ANALOG;
}
