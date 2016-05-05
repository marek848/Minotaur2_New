/*
 * lowLewel.h
 *
 *  Created on: Apr 27, 2016
 *      Author: Marek
 */

#ifndef LOWLEWEL_H_
#define LOWLEWEL_H_

#define PWMRIGHT TIM1->CCR2
#define PWMLEFT TIM1->CCR1
#define ENCODERRIGHT TIM2->CNT
#define ENCODERLEFT TIM3->CNT

void sendGyro(uint8_t Register, uint8_t Value);

void wheelDrive(uint16_t, uint8_t, uint8_t);

int32_t readRotationalSpeed(uint8_t);

#endif /* LOWLEWEL_H_ */
