/* ====================================================
 * STM32 OPEN SOURCE MULTIMETER
 * embedblog.eu/dmm
 * license: CC BY-NC-SA 4.0
 * ==================================================== */

#include "stm32f3xx.h"
#include "at24c.h"
#include "i2c.h"

uint8_t eeprom_address;

void at24c_init(uint8_t dev_adress)
{
	eeprom_address = dev_adress;
	
	i2c_init();
}

void at24c_write_byte(uint8_t address, uint8_t data)
{
	i2c_setSlaveAddress(eeprom_address);
	i2c_writeBuffer(address);
	i2c_writeBuffer(data);
	i2c_transmit();
}

void at24c_write_page(uint8_t address, uint8_t data[8])
{
	i2c_setSlaveAddress(eeprom_address);
	i2c_writeBuffer(address);
	
	for (uint8_t i = 0; i < 8; i ++)
		i2c_writeBuffer(data[i]);
	
	i2c_transmit();
}

uint8_t at24c_read_byte(uint8_t address)
{
	i2c_setSlaveAddress(eeprom_address);
	i2c_writeBuffer(address);
	i2c_transmit();
	
	i2c_setSlaveAddress(eeprom_address);
	i2c_request(1);
	
	return i2c_readBuffer(0);
}

uint8_t* at24c_read_page(uint8_t address)
{
	i2c_setSlaveAddress(eeprom_address);
	i2c_writeBuffer(address);
	i2c_transmit();
	
	i2c_setSlaveAddress(eeprom_address);
	i2c_request(8);
	
	static uint8_t page[8];
	for (uint8_t i = 0; i < 8; i ++)
		page[i] = i2c_readBuffer(i);
	
	return page;
}

void eeprom_save_floats(uint8_t address, float f0, float f1)
{
	uint8_t *f0_ptr, *f1_ptr;
	uint8_t data[8], i;
	
	f0_ptr = (uint8_t*)&f0;
	f1_ptr = (uint8_t*)&f1;
	for (i = 0; i < 4; i ++)
		data[i] = (*f0_ptr++);
	for (; i < 8; i ++)
		data[i] = (*f1_ptr++);
		
	at24c_write_page(address, data);
}

void eeprom_read_floats(uint8_t address, float& f0, float& f1)
{
	uint8_t* result_address;
	uint8_t i;
	
	result_address = at24c_read_page(address);
	
	for (i = 0; i < 4; i ++)
		*((uint8_t*)(&f0) + i) = *(result_address + i);
	for (i = 0; i < 4; i ++)
		*((uint8_t*)(&f1) + i) = *(result_address + i + 4);
	
}



