/*
 * status.cpp
 *
 *  Created on: May 5, 2023
 *      Author: flori
 */

#include "status.h"


bool get_userbutton(){
    if(HAL_GPIO_ReadPin (B1_GPIO_Port, B1_Pin)){
    	return true;
    }
    else{
    	return false;
    }
}



void led_green(int status){
	if (status==0){
			HAL_GPIO_WritePin(GPIOH, LED_GREEN_Pin, GPIO_PIN_RESET);
		}
		else if (status==1){
			HAL_GPIO_WritePin(GPIOH, LED_GREEN_Pin, GPIO_PIN_SET);
		}
}
void led_red(int status){
	if (status==0){
			HAL_GPIO_WritePin(GPIOH, LED_RED_Pin, GPIO_PIN_RESET);
		}
		else if (status==1){
			HAL_GPIO_WritePin(GPIOH, LED_RED_Pin, GPIO_PIN_SET);
		}
}




