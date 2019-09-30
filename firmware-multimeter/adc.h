#ifndef ADC_H
#define ADC_H

#define VBAT		0
#define TP1			2
#define TP2			1
#define REF			9

void adc1_init(void);
uint16_t adc1_getReading(uint8_t channel, uint8_t oversamplig = 8);

#endif
