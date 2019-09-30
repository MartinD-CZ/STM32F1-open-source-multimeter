#ifndef _CONFIG_H
#define _CONFIG_H

//==========================================================================
// USER SETTINGS - modify as you wish
#define SCREEN_TRANSISTION_DUR		1000			//in ms, how long the intro to each screen is displayed
#define SPLASH_SCREEN_DUR					2000			//in ms, how long the start up screen is displayed
#define SCREEN_UPDATE_RATE				2					//in Hz, how often is the measurement (V, I or P) screen refreshed
#define CONTINUITY_REFRESH				10				//in Hz, how often is the continuity screen refreshed

#define CONTINUITY_BUZZER					50				//in ohms, below this value the buzzer is sounded
#define IO_COMPENSATION						23

#define VREF											1.8f
#define VSUP											2.99f			//TODO: add to EEPROM

//#define RAW_OUTPUT

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

#define LED_RED							GPIOB->BSRR = GPIO_BSRR_BS_6 | GPIO_BSRR_BR_7
#define LED_GREEN						GPIOB->BSRR = GPIO_BSRR_BR_6 | GPIO_BSRR_BS_7
#define LED_NONE						GPIOB->BSRR = GPIO_BSRR_BS_6 | GPIO_BSRR_BS_7

#define MODE_VOLTAGE				0
#define MODE_CURRENT				1
#define MODE_POWER					2
#define MODE_CONT						3
#define MODE_COMPTEST				4
#define MODE_FREQUENCY			5
#define MODES								6

#define DATA_SAVED					0xC0

//==========================================================================
// COMPONENT TEST IO
#define TP1L_HIGHZ					GPIOB->MODER &=~ GPIO_MODER_MODER14
#define TP1L_LOW						GPIOB->MODER |= GPIO_MODER_MODER14_0; GPIOB->BSRR = GPIO_BSRR_BR_14
#define TP1L_HIGH						GPIOB->MODER |= GPIO_MODER_MODER14_0; GPIOB->BSRR = GPIO_BSRR_BS_14

#define TP1M_HIGHZ					GPIOA->MODER &=~ GPIO_MODER_MODER6
#define TP1M_LOW						GPIOA->MODER |= GPIO_MODER_MODER6_0; GPIOA->BSRR = GPIO_BSRR_BR_6
#define TP1M_HIGH						GPIOA->MODER |= GPIO_MODER_MODER6_0; GPIOA->BSRR = GPIO_BSRR_BS_6

#define TP1H_HIGHZ					GPIOB->MODER &=~ GPIO_MODER_MODER15
#define TP1H_LOW						GPIOB->MODER |= GPIO_MODER_MODER15_0; GPIOB->BSRR = GPIO_BSRR_BR_15
#define TP1H_HIGH						GPIOB->MODER |= GPIO_MODER_MODER15_0; GPIOB->BSRR = GPIO_BSRR_BS_15

#define TP1A_ANALOG					GPIOA->MODER |= GPIO_MODER_MODER2
#define TP1A_LOW						GPIOA->MODER &=~GPIO_MODER_MODER2_1; GPIOB->BSRR = GPIO_BSRR_BR_2
#define TP1A_HIGH						GPIOA->MODER &=~GPIO_MODER_MODER2_1; GPIOB->BSRR = GPIO_BSRR_BS_2

#define TP2L_HIGHZ					GPIOA->MODER &=~ GPIO_MODER_MODER5
#define TP2L_LOW						GPIOA->MODER |= GPIO_MODER_MODER5_0; GPIOA->BSRR = GPIO_BSRR_BR_5
#define TP2L_HIGH						GPIOA->MODER |= GPIO_MODER_MODER5_0; GPIOA->BSRR = GPIO_BSRR_BS_5

#define TP2M_HIGHZ					GPIOA->MODER &=~ GPIO_MODER_MODER4
#define TP2M_LOW						GPIOA->MODER |= GPIO_MODER_MODER4_0; GPIOA->BSRR = GPIO_BSRR_BR_4
#define TP2M_HIGH						GPIOA->MODER |= GPIO_MODER_MODER4_0; GPIOA->BSRR = GPIO_BSRR_BS_4

#define TP2H_HIGHZ					GPIOA->MODER &=~ GPIO_MODER_MODER3
#define TP2H_LOW						GPIOA->MODER |= GPIO_MODER_MODER3_0; GPIOA->BSRR = GPIO_BSRR_BR_3
#define TP2H_HIGH						GPIOA->MODER |= GPIO_MODER_MODER3_0; GPIOA->BSRR = GPIO_BSRR_BS_3

#define TP2A_ANALOG					GPIOA->MODER |= GPIO_MODER_MODER1
#define TP2A_LOW						GPIOA->MODER &=~GPIO_MODER_MODER1_1; GPIOB->BSRR = GPIO_BSRR_BR_1
#define TP2A_HIGH						GPIOA->MODER &=~GPIO_MODER_MODER1_1; GPIOB->BSRR = GPIO_BSRR_BS_1

#endif
