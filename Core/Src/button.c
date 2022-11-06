
#include "button.h"


int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int timerForKeyPress = 100;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button_RESET_LongPressed_flag = 0;
int button_INC_LongPressed_flag = 0;
int button_DEC_LongPressed_flag = 0;


int isButton1Pressed()
{
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton2Pressed()
{
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton3Pressed()
{
	if(button3_flag == 1)
	{
		button3_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_RESET_LongPressed(){
	if(button_RESET_LongPressed_flag == 1){
		button_RESET_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_INC_LongPressed(){
	if(button_INC_LongPressed_flag == 1){
		button_INC_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_DEC_LongPressed(){
	if(button_DEC_LongPressed_flag == 1){
		button_DEC_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}

void getKeyInput()
{
	for(int i = 0; i < 3; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		if(i == 0){
			keyReg2[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i])
				{
					keyReg3[i] = keyReg2[i];
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button1_flag = 1;
						timerForKeyPress = 100;
					}
				}
				else
				{
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
								//TODO
								button_RESET_LongPressed_flag = 1;
							timerForKeyPress = 100;
						}
					}

				}

			}
		}
		if(i == 1){
			keyReg0[i] = keyReg1[i];
			keyReg1[i] = keyReg2[i];
			keyReg2[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i])
				{
					keyReg3[i] = keyReg2[i];
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button2_flag = 1;
						timerForKeyPress = 100;
					}
				}
				else
				{// trường hợp nhấn đè
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
								//TODO
								button_INC_LongPressed_flag = 1;
							timerForKeyPress = 100;
						}
					}

				}

			}
		}
		if(i == 2){
			keyReg0[i] = keyReg1[i];
			keyReg1[i] = keyReg2[i];
			keyReg2[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i]) //trường hợp nhấn thả
				{
					keyReg3[i] = keyReg2[i]; // cập nhật lại keyReg3
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button3_flag = 1;
						timerForKeyPress = 100;
					}
				}
				else
				{// trường hợp nhấn đè
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
							//if(keyReg2 == PRESSED_STATE)
							//{
								//TODO
								button_DEC_LongPressed_flag = 1;
							//}
							timerForKeyPress = 100;
						}
					}
				}
			}
		}

	}
}


