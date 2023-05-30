/*
 * battery_node.h
 *
 *  Created on: May 2, 2023
 *      Author: flori
 */

#ifndef ROS_BATTERY_BATTERY_NODE_H_
#define ROS_BATTERY_BATTERY_NODE_H_


#include "main.h"



void get_voltage();
int cell_count();
void get_cell_voltage();
void get_percentage();



#endif /* ROS_BATTERY_BATTERY_NODE_H_ */
