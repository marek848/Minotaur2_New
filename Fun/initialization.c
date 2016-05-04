 /**
  ******************************************************************************
  * File Name          : initialization.c
  * Description        : Initialization peripheral function
  ******************************************************************************
 */
#include "main.h"

void encoderInit()
{
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
}

void  pwmInit()
{
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
}

void adcInit()
{
	HAL_ADCEx_Calibration_Start(&hadc1);
//	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcData, ADC_SIZE);
}

void uartInit()
{
	HAL_UART_MspInit(&huart3);
	HAL_UART_Receive_DMA(&huart3,(uint8_t*)rxBuffer,RX_BUFFER_SIZE);
}

void timInterruptInit()
{
	HAL_TIM_Base_Start_IT(&htim4);
}

void gyroInit(uint8_t speed)
{
	sendGyro(0x20,0xDF);//4F
	sendGyro(0x21,0x00);
	sendGyro(0x22,0x00);
	switch(speed)
	{
		case 1: /// Low Speed - 250 dps (8.75 mdps/digit)
			sendGyro(0x23,0x00);
			break;
		case 2: /// Medium Speed - 500 dps (17.5 mdps/digit)
			sendGyro(0x23,0x10);
			break;
		case 3: /// High Speed - 2000 dps (70 mdps/digit)
			sendGyro(0x23,0x20);
			break;
	}
	sendGyro(0x24,0x00);

}
