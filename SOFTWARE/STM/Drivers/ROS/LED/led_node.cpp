/*
 * led_node.cpp
 *
 *  Created on: 5 May 2023
 *      Author: flori
 */

#include "led_node.h"


void led(int status){ //0 -> OFF 1 -> on

	if (status==0){
		HAL_GPIO_WritePin(LED_White_GPIO_Port, LED_White_Pin, GPIO_PIN_RESET);
	}
	else if (status==1){
		HAL_GPIO_WritePin(LED_White_GPIO_Port, LED_White_Pin, GPIO_PIN_SET);
	}

}


