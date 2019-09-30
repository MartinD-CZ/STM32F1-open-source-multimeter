#ifndef _CONFIG_H
#define _CONFIG_H

//==========================================================================
// USER SETTINGS - modify as you wish
#define SCREEN_TRANSISTION_TIME		1000			//in ms, how long the intro to each screen is displayed
#define SCREEN_UPDATE_RATE				2					//in Hz, how often is the measurement (V, I or P) screen refreshed
#define CONTINUITY_REFRESH				10				//in Hz, how often is the continuity screen refreshed

#define VREF											1.8f

#define LED_RED							GPIOB->BSRR = GPIO_BSRR_BS_6 | GPIO_BSRR_BR_7
#define LED_GREEN						GPIOB->BSRR = GPIO_BSRR_BR_6 | GPIO_BSRR_BS_7
#define LED_NONE						GPIOB->BSRR = GPIO_BSRR_BS_6 | GPIO_BSRR_BS_7

//==========================================================================
// SYSTEM SETTINGS - do not modify, unless you know what you're doing
#define BUZZER_ON						GPIOA->BSRR = GPIO_BSRR_BS_8
#define BUZZER_OFF					GPIOA->BSRR = GPIO_BSRR_BR_8

#define VSEL0_LOW						GPIOF->BSRR = GPIO_BSRR_BR_6
#define VSEL0_HIGH					GPIOF->BSRR = GPIO_BSRR_BS_6
#define VSEL1_LOW						GPIOF->BSRR = GPIO_BSRR_BR_7
#define VSEL1_HIGH					GPIOF->BSRR = GPIO_BSRR_BS_7

#define ISEL_HIGH						GPIOB->BSRR = GPIO_BSRR_BS_2
#define ISEL_LOW						GPIOB->BSRR = GPIO_BSRR_BR_2

#define OFSEL_GND						GPIOA->BSRR = GPIO_BSRR_BS_12
#define OFSEL_VREF2					GPIOA->BSRR = GPIO_BSRR_BR_12

#define MODE_VOLTAGE				0
#define MODE_CURRENT				1
#define MODE_POWER					2
#define MODE_CONT						3
#define MODE_COMPTEST				4
#define MODE_ABOUT					5
#define MODES								6

#define DATA_SAVED					0xC0

//==========================================================================
// DEBUG SETTINGS - used mostly for development
#define DEBUG_IO

#ifdef DEBUG_IO
	#define PB8_LOW							GPIOB->BSRR = GPIO_BSRR_BR_8
	#define PB8_HIGH						GPIOB->BSRR = GPIO_BSRR_BS_8
	#define PB9_LOW							GPIOB->BSRR = GPIO_BSRR_BR_9
	#define PB9_HIGH						GPIOB->BSRR = GPIO_BSRR_BS_9
#else
	#define PB8_LOW
	#define PB8_HIGH
	#define PB9_LOW
	#define PB9_HIGH
#endif

#endif
