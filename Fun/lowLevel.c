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

int8_t readGyro(uint8_t Register)
{
	uint8_t Read=0;
	HAL_I2C_Master_Transmit(&hi2c1,0x6B<<1,&Register,1,10);
	HAL_I2C_Master_Receive(&hi2c1,0x6B<<1,&Read,1,10);

	return Read;
}

int16_t readAxis(uint8_t Register)
{
	int16_t Measurement=0;
	int8_t LSB=0;
	int8_t MSB=0;

	LSB=readGyro(Register);
	MSB=readGyro(Register+1);

	Measurement=(MSB<<8)+LSB;
	return Measurement;
}

void integrateGyro()
{
	static int32_t prevRate;
	static int32_t rotVel;

	rotVel=((readAxis(0x2C)-dryfGyro)*scaleGyro)/10000;
	angle +=(prevRate + rotVel);
	prevRate=rotVel;
}

void calibrateGyro()
{
	int i;

	HAL_Delay(1000);
	 for(i=0;i<100;i++)
	 {
		dryfGyro += readAxis(0x2C);
	 }
	 dryfGyro/=100;
}

void wheelDrive(uint16_t speed,uint8_t wheel, uint8_t direction)
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
			tmpRate=ENCODERLEFT;//-16384;
//			ENCODERLEFT=16384;
			break;
		case RIGHTWHEEL:
			tmpRate=ENCODERRIGHT;//-16384;
//			ENCODERRIGHT=16384;
			break;
	}
	return tmpRate;
};
