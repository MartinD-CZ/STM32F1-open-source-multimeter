#ifndef _I2C_H
#define _I2C_H

#define TX_BUFFER_SIZE		12
#define RX_BUFFER_SIZE		12

void i2c_init();
void i2c_setSlaveAddress(uint8_t add);
void i2c_writeBuffer(uint8_t data);
void i2c_transmit();
void i2c_request(uint8_t bytes);
uint8_t i2c_readBuffer(uint8_t pos);

#endif
