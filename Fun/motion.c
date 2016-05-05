 /**
  ******************************************************************************
  * File Name          : motion.c
  * Description        : Function related to motion
  ******************************************************************************
 */

#include "motion.h"

void drive(uint16_t maxSpeed)
{
	int32_t speed[2];
	int32_t regulator;
	ENCODERLEFT=0;
	ENCODERRIGHT=0;
	distance=0;
	while(distance<DISTANCE)
	{
//		if (SensorTab[2][indexer]-dys0[2]>SSL_Tresh && SensorTab[0][indexer]-dys0[0] >SSL_Tresh && abs(SensorTab[2][indexer]-dys0[2]-(SensorTab[0][indexer]-dys0[0]))<80)
//		{
//			error=(SensorTab[0][indexer]-dys0[0]-(SensorTab[2][indexer]-dys0[2]))*3/2 - (SensorTab[0][indexer]-dys0[0])*5/2-angle1/90;
//		}
//		else if(SensorTab[3][indexer]-dys0[3]>SSR_Tresh && SensorTab[1][indexer]-dys0[1]>SSR_Tresh && abs(SensorTab[3][indexer]-dys0[3]-(SensorTab[1][indexer]-dys0[1]))<80)
//		{
//			error= (SensorTab[3][indexer]-dys0[3]-(SensorTab[1][indexer]-dys0[1]))*3/2 + (SensorTab[1][indexer]-dys0[1])*5/2-angle1/90;
//		}
//		else error=-angle1/30;

//		propocjonal=error*K_drive;
//
//		integral+=error*I_drive;
//		if (integral>1000) integral=100;
//		if (integral<-1000) integral=-100;
//
//		derivative=(error-error2)*D_drive;
//		error2=error;
//		regulator=propocjonal+integral+derivative;

		regulator=0;

		speed[0]=maxSpeed-regulator;
		speed[1]=maxSpeed+regulator;

		if(speed[0]>999) speed[0]=999;
		else if(speed[0]<0) speed[0]=0;
		if(speed[1]>999) speed[1]=999;
		else if(speed[1]<0) speed[1]=0;

		wheelDrive(speed[0],LEFTWHEEL,FORWARD);
		wheelDrive(speed[1],RIGHTWHEEL,FORWARD);

		distance=(readRotationalSpeed(LEFTWHEEL)+readRotationalSpeed(RIGHTWHEEL))/2;
	}
	wheelDrive(0,LEFTWHEEL,FORWARD);
	wheelDrive(0,RIGHTWHEEL,FORWARD);
};

void rotary(uint16_t maxSpeed)
{
	angle=0;
	while(angle<190000)
	{
		wheelDrive(maxSpeed,LEFTWHEEL,BACKWARD);
		wheelDrive(maxSpeed,RIGHTWHEEL,FORWARD);
	}
	wheelDrive(0,LEFTWHEEL,BACKWARD);
	wheelDrive(0,RIGHTWHEEL,FORWARD);
};

void rotaryLeft(uint16_t maxSpeed)
{
	angle=0;
	while(angle<85000)
	{
		wheelDrive(maxSpeed,LEFTWHEEL,BACKWARD);
		wheelDrive(maxSpeed,RIGHTWHEEL,FORWARD);
	}
	wheelDrive(0,LEFTWHEEL,BACKWARD);
	wheelDrive(0,RIGHTWHEEL,FORWARD);
};

void rotaryRight(uint16_t maxSpeed)
{
	angle=0;
	while(angle>-80000)
	{
		wheelDrive(maxSpeed,LEFTWHEEL,FORWARD);
		wheelDrive(maxSpeed,RIGHTWHEEL,BACKWARD);
	}
	wheelDrive(0,LEFTWHEEL,BACKWARD);
	wheelDrive(0,RIGHTWHEEL,FORWARD);
};
