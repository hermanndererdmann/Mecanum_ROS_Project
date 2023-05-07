/*
 * motordriver_node.h
 *
 *  Created on: May 5, 2023
 *      Author: flori
 */

#ifndef ROS_MOTOR_DRIVER_MOTORDRIVER_NODE_H_
#define ROS_MOTOR_DRIVER_MOTORDRIVER_NODE_H_

#include "main.h"



int drive(float Ax, float Ay, float Rz);
bool check_angle(float angle);




#endif /* ROS_MOTOR_DRIVER_MOTORDRIVER_NODE_H_ */
