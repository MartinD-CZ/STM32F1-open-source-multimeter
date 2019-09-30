#ifndef _AT24C_H
#define _AT24C_H

void at24c_init(uint8_t dev_adress);
void at24c_write_byte(uint8_t address, uint8_t data);
void at24c_write_page(uint8_t address, uint8_t data[8]);
uint8_t at24c_read_byte(uint8_t address);
uint8_t* at24c_read_page(uint8_t address);

void eeprom_save_floats(uint8_t address, float f0, float f1);
void eeprom_read_floats(uint8_t address, float& f0, float& f1);

#endif
