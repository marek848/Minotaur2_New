#include "main.h"
void sendGyro(uint8_t Register, uint8_t Value)
{
	uint8_t ToSend[2]={Register,Value};
	HAL_I2C_Master_Transmit(&hi2c1,0x6B<<1,ToSend,2,10);
}

void wheelDrive(uint8_t a,uint8_t b, uint8_t c)
{

};
