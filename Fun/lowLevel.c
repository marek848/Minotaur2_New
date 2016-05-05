 /**
  ******************************************************************************
  * File Name          : lowLevel.c
  * Description        : Low level function
  ******************************************************************************
 */

#include "main.h"

void sendGyro(uint8_t Register, uint8_t Value)
{
	uint8_t ToSend[2]={Register,Value};
	HAL_I2C_Master_Transmit(&hi2c1,0x6B<<1,ToSend,2,10);
}

void wheelDrive(uint8_t speed,uint8_t wheel, uint8_t direction)
{
	switch(wheel)
	{
		case RIGHTWHEEL:
			switch(direction)
			{
				case FORWARD:
					HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,0);
					HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,1);
					break;
				case BACKWARD:
					HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,1);
					HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,0);
			}
			PWMRIGHT=speed;
			break;
		case LEFTWHEEL:
			switch(direction)
			{
				case FORWARD:
					HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,0);
					HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,1);
					break;
				case BACKWARD:
					HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,1);
					HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,0);
					break;
			}
			PWMLEFT=speed;
			break;
	}
};

int32_t readRotationalSpeed(uint8_t wheel)
{
	int32_t tmpRate=0;

	switch(wheel)
	{
		case LEFTWHEEL:
			tmpRate=ENCODERLEFT-16384;
			ENCODERLEFT=16384;
			break;
		case RIGHTWHEEL:
			tmpRate=ENCODERRIGHT-16384;
			ENCODERRIGHT=16384;
			break;
	}
	return tmpRate*2; ///tymczasowy mnoznik
};
