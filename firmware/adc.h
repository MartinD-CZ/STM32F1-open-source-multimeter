#ifndef ADC_H
#define ADC_H

void adc1_init(void);
void adc1_start(void);
void adc1_stop(void);
void adc2_init(void);
uint16_t adc2_getReading(uint8_t channel, uint8_t oversamplig = 4);

#endif
