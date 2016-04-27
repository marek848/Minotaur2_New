/*
 * initialization.c
 *
 *  Created on: Apr 27, 2016
 *      Author: Marek
 */

void encoderInit()
{
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
}

void adcInit()
{
	HAL_ADCEx_Calibration_Start(&hadc1);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcData, 6);
}

void uartInit()
{
	HAL_UART_MspInit(&huart3);
//	HAL_UART_Receive_DMA(&huart3,(uint8*)RxBuffer,1);

}
