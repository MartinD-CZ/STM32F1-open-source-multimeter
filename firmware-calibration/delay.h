#ifndef DELAY_H
#define DELAY_H

void _delay_ms(uint16_t ms);
void _delay_us(uint16_t us);
void _delay_init(void);
void _count_us_start(void);
uint16_t _count_us_stop(void);

#endif
