/*
 * main.h
 *
 *  Created on: Apr 27, 2016
 *      Author: Marek
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f1xx_hal.h"
#include "initialization.h"
#include "motion.h"
#include "lowLewel.h"

/**************************************** Constant and enumerate define *************************************/
#define ADC_SIZE 6
#define RX_BUFFER_SIZE 8
#define TX_BUFFER_SIZE
#define VEL 400
#define RVEL 800
#define DISTANCE 2500

enum direction {
	LEFT = 0,
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
};
enum gyroSpeed {
	GYROLOW,
	GYROMEDIUM,
	GYROHIGH,
};
enum sensors {
	SENLB = 0,
	SENRB = 1,
	SENLF = 2,
	SENRF = 3,
	SENFL = 4,
	SENFR = 5,
};
enum wheel {
	LEFTWHEEL,
	RIGHTWHEEL,
	FORWARD,
	BACKWARD,
};

/****************************************** Peripheral structure ********************************************/
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern RTC_HandleTypeDef hrtc;

extern SPI_HandleTypeDef hspi2;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart3_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;

/********************************************* Global variables ********************************************/
volatile uint16_t adcDataOn[6],adcDataOff[6];

volatile int32_t angle;
volatile int32_t scaleGyro;
volatile int32_t dryfGyro;
volatile encoder_tmp;
volatile int32_t distance;

volatile uint8_t rxBuffer[RX_BUFFER_SIZE];
volatile uint8_t txBuffer[TX_BUFFER_SIZE];


#endif /* MAIN_H_ */
