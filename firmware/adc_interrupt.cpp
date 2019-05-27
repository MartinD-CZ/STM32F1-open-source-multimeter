//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// CC BY-NC-SA 4.0
// ===================================================

#include "stm32f10x.h"
#include "defines.h"
#include "math.h"

volatile int64_t adc1_V_avg;
volatile int64_t adc1_I_avg;
volatile uint64_t adc1_V_rms;
volatile uint64_t adc1_I_rms;
volatile uint64_t adc1_vsup_avg;
volatile uint16_t adc1_samples;

volatile float adc1_result_vsup;
volatile float adc1_result_V_avg;
volatile float adc1_result_V_rms;
volatile float adc1_result_I_avg;
volatile float adc1_result_I_rms;
volatile uint16_t adc1_result_samples;

extern volatile uint16_t adc_data[12];
extern volatile bool screen_update, rangeV, rangeI, aquisition;

const static float vref = 1.249625;
const static float gain_6V = (1247.0 / 247);
const static float gain_60V = (1020.0 / 20);
const static float gain_60mA = 0.103;
const static float gain_500mA = 0.98;

extern "C"
{
	//DMA1 CH1 interrupt - ADC1 TRANSFER
	void DMA1_Channel1_IRQHandler(void)
	{
		if ((DMA1->ISR & DMA_ISR_TCIF1) == DMA_ISR_TCIF1)
		{
			int16_t data_V = adc_data[1] + adc_data[4] + adc_data[7] + adc_data[10];
			int16_t data_I = adc_data[0] + adc_data[3] + adc_data[6] + adc_data[9];
			int16_t data_vref = adc_data[2] + adc_data[5] + adc_data[8] + adc_data[11];
			adc1_vsup_avg += data_vref;
			
			data_V -= data_vref;
			data_I -= data_vref;
			
			data_V /= 4;
			data_I /= 4;
			
			adc1_V_avg += data_V;
			adc1_V_rms += data_V * data_V;
			adc1_I_avg += data_I;
			adc1_I_rms += data_I * data_I;
	
			adc1_samples++;
			
			DMA1->IFCR = DMA_IFCR_CTCIF1;
		}
	}
	
	//TIMER2 - used to update data
	void TIM2_IRQHandler(void)
	{
		//CC1
		if ((TIM2->SR & TIM_SR_CC1IF) == TIM_SR_CC1IF)
		{
			TIM2->CNT = 0x00;
			
			adc1_result_samples = adc1_samples;
			
			adc1_vsup_avg /= (4 * adc1_result_samples);
			adc1_result_vsup = vref * 4096 / adc1_vsup_avg;
			
			if (aquisition)
			{
				adc1_result_V_avg = ((float)adc1_V_avg / adc1_result_samples) * (adc1_result_vsup / 4096.0) * (rangeV ? gain_60V : gain_6V);
				adc1_result_I_avg = ((float)adc1_I_avg / adc1_result_samples) * (adc1_result_vsup / 4096.0) * (rangeI ? gain_500mA : gain_60mA);
			}
			else
			{
				adc1_result_V_rms = sqrt((float)adc1_V_rms / adc1_result_samples) * (adc1_result_vsup / 4096.0) * (rangeV ? gain_60V : gain_6V);
				adc1_result_I_rms = sqrt((float)adc1_I_rms / adc1_result_samples) * (adc1_result_vsup / 4096.0) * (rangeI ? gain_500mA : gain_60mA);
			}
			
			adc1_V_avg = 0;
			adc1_I_avg = 0;
			adc1_V_rms = 0;
			adc1_I_rms = 0;
			adc1_vsup_avg = 0;
			adc1_samples = 0;
			
			screen_update = true;

			TIM2->SR &=~TIM_SR_CC1IF;
		}
	}
}
