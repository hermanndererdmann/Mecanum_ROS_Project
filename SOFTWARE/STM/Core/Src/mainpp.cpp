/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <main.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <mainpp.h>
#include <motor_controller.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <math.h>
#include "lis3mdl.h"

/* USER CODE END Includes */
int speed = 0;
double turnPower = 100;
double translationPower = 400;
double linear_x=0;
double linear_y=0;
double linear_z=0;

double angular_x=0;
double angular_y=0;
double angular_z=0;

double ADPower = 0;
double BCPower = 0;

double mot_speed_1=0;
double mot_speed_2=0;
double mot_speed_3=0;
double mot_speed_4=0;

//IMU
float accel = 0;
float omega = 0;
float stime = 0;
float t0 = 0;
float dt = 0;

//Variable init
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;


ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
ros::Subscriber<geometry_msgs::Twist> motor_msg("cmd_vel", &cmd_vel);


void cmd_vel(const geometry_msgs::Twist& msg)
{
	linear_x = msg.linear.x;
	linear_y = msg.linear.y;
	linear_z = msg.linear.z;
	angular_x = msg.angular.x;
	angular_y = msg.angular.y;
	angular_z = msg.angular.z;

//	void setMecanumDrive( angular_z,  translationPower,  turnPower);
	printf("cmd_vel_angular_x:%f \n\r",angular_x);
	printf("cmd_vel_angular_y:%f \n\r",angular_y);
	printf("cmd_vel_angular_z:%f \n\r",angular_z);
	printf("cmd_vel_x:%f \n\r",linear_x);
	printf("cmd_vel_y:%f \n\r",linear_y);
	printf("cmd_velz:%f \n\r",linear_z);



	// calculate motor power
	ADPower = abs(translationPower * sqrt(2) * 0.5 * (linear_x + linear_y));
	BCPower = abs(translationPower * sqrt(2) * 0.5 * (linear_x - linear_y));
	printf("ADPower,%f \n\r",ADPower);
	printf("BCPower,%f \n\r",BCPower);

	mot_speed_1 = ADPower;
	mot_speed_2 = BCPower;
	mot_speed_3 = ADPower;
	mot_speed_4 = BCPower;

	//drive forwards
		if ((linear_x >= 0.1) && (angular_z == 0))
		{
			motor_driver(0, 400); //int dir (direction), int speed (motor speed 0-1000)
		}

	//right
		else if	((linear_y < 0) && (linear_x < 0.1) && (angular_z == 0) && (linear_x > -0.1))
		{
			motor_driver(90, 400); //int dir (direction), int speed (motor speed 0-1000)
		}


	//drive backwards
		else if ((linear_x <= -0.1) && (angular_z == 0))
		{
			motor_driver(180, 400); //int dir (direction), int speed (motor speed 0-1000)
		}


	//left
		else if	((linear_y > 0) && (linear_x < 0.1) && (angular_z == 0)&& (linear_x > -0.1))
		{
			motor_driver(270, 400); //int dir (direction), int speed (motor speed 0-1000)
		}

	//turn right
		else if ((linear_y == 0) && (linear_x == 0) && (angular_z < 0.5))
		{
			motor_driver(7, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_1 = mot_speed_2 = mot_speed_3 = mot_speed_4 = abs(translationPower * sqrt(2) * 0.5 * angular_z);
		}

	//turn left
		else if ((linear_y == 0) && (linear_x == 0) && (angular_z > -0.5))
		{
			motor_driver(8, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_1 = mot_speed_2 = mot_speed_3 = mot_speed_4 = abs(translationPower * sqrt(2) * 0.5 * angular_z);
		}
	//Pivot right forward
		else if ((linear_x > 0) && (angular_z < 0))
		{
			motor_driver(0, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_1 = mot_speed_2 = abs(translationPower * sqrt(2) * 0.5 * angular_z);
			mot_speed_3 = mot_speed_4 = 0;
		}

	//Pivot left forward
		else if ((linear_x > 0) && (angular_z > 0))
		{
			motor_driver(0, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_3 = mot_speed_4  = abs(translationPower * sqrt(2) * 0.5 * angular_z);
			mot_speed_1 = mot_speed_2 = 0;
		}

	//Pivot right forward
		else if ((linear_x < 0) && (angular_z < 0))
		{
			motor_driver(180, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_1 = mot_speed_2 = abs(translationPower * sqrt(2) * 0.5 * angular_z);
			mot_speed_3 = mot_speed_4 = 0;
		}

	//Pivot left forward
		else if ((linear_x < 0) && (angular_z > 0))
		{
			motor_driver(180, 400); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_3 = mot_speed_4  = abs(translationPower * sqrt(2) * 0.5 * angular_z);
			mot_speed_1 = mot_speed_2 = 0;
		}


	//stop
		else
		{
			motor_driver(1, 0); //int dir (direction), int speed (motor speed 0-1000)
			mot_speed_1 = mot_speed_2 = mot_speed_3 = mot_speed_4 = 0;
		}
		// PWM M1
		htim2.Instance->CCR1 = mot_speed_1;
		// PWM M2
		htim2.Instance->CCR3 = mot_speed_2;
		// PWM M3
		htim3.Instance->CCR1 = mot_speed_3;
		// PWM M4
		htim2.Instance->CCR2 = mot_speed_4;

	}

char hello[] = "It's the STM32";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}




void setup(void)
{
	HAL_GPIO_WritePin(GPIOA, LED_Pin, GPIO_PIN_SET);

	 nh.initNode();
	 nh.subscribe(motor_msg);
	 nh.advertise(chatter);

}

void loop(void)
{

	str_msg.data = hello;

	chatter.publish(&str_msg);

	nh.spinOnce();

	HAL_Delay(10);
}
