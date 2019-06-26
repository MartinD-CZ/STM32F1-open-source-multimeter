#ifndef DEFINES_H
#define DEFINES_H

//==========================================================================
// USER SETTINGS - modify as you wish

#define SCREEN_TRANSISTION_TIME		1000			//in ms, how long the intro to each screen is displayed

#define SCREEN_UPDATE_RATE				2					//in Hz, how often is the measurement (V, I or P) screen refreshed

#define CONTINUITY_REFRESH				10				//in Hz, how often is the continuity screen refreshed


//==========================================================================
// SYSTEM SETTINGS - do not modify, unless you know what you're doing
#define LED_OFF							GPIOA->BSRR = GPIO_BSRR_BS3
#define LED_ON							GPIOA->BSRR = GPIO_BSRR_BS3

#define BUZZER_ON						GPIOA->BSRR = GPIO_BSRR_BS12
#define BUZZER_OFF					GPIOA->BSRR = GPIO_BSRR_BR12

#define VSEL0_LOW						GPIOC->BSRR = GPIO_BSRR_BR13
#define VSEL0_HIGH					GPIOC->BSRR = GPIO_BSRR_BS13
#define VSEL1_LOW						GPIOC->BSRR = GPIO_BSRR_BR14
#define VSEL1_HIGH					GPIOC->BSRR = GPIO_BSRR_BS14

#define ISEL_HIGH						GPIOA->BSRR = GPIO_BSRR_BS4
#define ISEL_LOW						GPIOA->BSRR = GPIO_BSRR_BR4

#define MODE_VOLTAGE				0
#define MODE_CURRENT				1
#define MODE_POWER					2
#define MODE_CONT						3
#define MODE_COMPTEST				4
#define MODE_ABOUT					5
#define MODES								6

#define VBAT								0
#define TP1									1
#define TP2									2
#define TP3									3

#endif
