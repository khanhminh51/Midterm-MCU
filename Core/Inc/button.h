/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

int isButton_RESET_LongPressed();
int isButton_INC_LongPressed();
int isButton_DEC_LongPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
