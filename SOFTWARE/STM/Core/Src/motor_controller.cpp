/*
 * motor_controller.cpp
 *
 *  Created on: Nov 14, 2022
 *      Author: tim_g
 */


#include "motor_controller.h"
#include "main.h"


//Variable init
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

//set GPIOs
void motor_driver(int dir, int speed) //int dir (direction), int speed (motor speed 0-1000)
{
	//Holonomic
	//forward
	if(dir == 0)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}
	// right
	else if(dir == 90)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}
	// backwards
	else if (dir == 180)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
	}

	//left
	else if(dir == 270)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
	}
	// stop
	else if(dir == 1)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
	}

	// normal moving

	//pivot right front
	else if(dir == 2)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}

	//pivot left front
	else if(dir == 3)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}

	//pivot Sideways right front
	else if(dir == 4)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}
	//pivot Sideways left front
	else if(dir == 5)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}
	//pivot Sideways left front
	else if(dir == 6)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}

	//Rotate right
	else if(dir == 7)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
	}
	//Rotate left
	else if(dir == 8)
	{
		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
	}

}




//	// 0 Grad
//	if(dir == 0)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
//	}
//
//	// 45 Grad
//	else if(dir == 45)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
//	}
//
//	// 90 Grad
//	else if(dir == 90)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
//	}
//
//	// 135 Grad
//	else if(dir == 135)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
//	}
//
//
//	// 180 Grad
//	else if (dir == 180)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
//	}
//
//	// 225 Grad
//	else if(dir == 225)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
//	}
//
//	// 270 Grad
//	else if(dir == 270)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_SET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_SET);
//	}
//
//	// 315 Grad
//	else if(dir == 315)
//	{
//		HAL_GPIO_WritePin(GPIOC, M1_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC, M1_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M3_IN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(M3_IN1_GPIO_Port, M3_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOB, M2_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, M2_IN1_Pin, GPIO_PIN_RESET);
//
//		HAL_GPIO_WritePin(GPIOC, M4_IN0_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOC, M4_IN1_Pin, GPIO_PIN_RESET);
//	}
//





