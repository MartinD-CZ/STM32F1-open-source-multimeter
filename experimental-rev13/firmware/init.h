#ifndef INIT_H
#define INIT_H

#define DATA_SAVED		0xC4

void init_rcc(void);
void init_gpio(void);
void init_exti(void);
void init_rtc(void);
void init_timer2(void);

#endif
