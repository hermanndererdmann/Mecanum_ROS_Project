/*
 * motordriver_node.cpp
 *
 *  Created on: May 5, 2023
 *      Author: flori
 */


#include "motordriver_node.h"


#define Kp 1.0f
#define Ki 0.0f
#define Kd 0.0f

float prev_error = 0.0;
float integral = 0.0;
float acceptable_error_deg = 1.0;



int drive(float Ax, float Ay, float Rz){

	//TODO:
	//Control all axis






	//Check angle and correct



}


bool check_angle(float desired_angle){
	float angle = get_angle();
	float error = desired_angle - angle;

	if (error <= acceptable_error_deg){
		return true;
	}
	else{
		integral += error;
		float derivative = error - prev_error;
		prev_error = error;
		float output = Kp * error + Ki * integral + Kd * derivative;
		// TODO: apply output to actuator



		return false;
	}


}
