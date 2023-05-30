/*
 * battery_node.cpp
 *
 *  Created on: May 2, 2023
 *      Author: flori
 */

//Corresponding number from LIPO cell to ADC Channel
#define BAT1_1 1
#define BAT1_2 4
#define BAT1_3 7
#define BAT1_4 6
#define BAT1_5 8
#define BAT1_6 9
#define BAT2_1 11
#define BAT2_2 2
#define BAT2_3 3
#define BAT2_4 5
#define BAT2_5 10
#define BAT2_6 0



#include "battery_node.h"


static double adc_convert=(3.3/4096)*(10000+30000)/30000;

extern uint32_t adc1_buf[12];

float bat1_cell[6]={0};
float bat2_cell[6]={0};

float bat1_voltage=0;
float bat2_voltage=0;

int bat_percentage=0;
int battery1_percent=0; //Single Bat
int battery2_percent=0; //Single Bat


void get_cell_voltage(){
	bat1_cell[0]=adc1_buf[BAT1_1]*adc_convert;
	bat1_cell[1]=adc1_buf[BAT1_2]*adc_convert;
	bat1_cell[2]=adc1_buf[BAT1_3]*adc_convert;
	bat1_cell[3]=adc1_buf[BAT1_4]*adc_convert;
	bat1_cell[4]=adc1_buf[BAT1_5]*adc_convert;
	bat1_cell[5]=adc1_buf[BAT1_6]*adc_convert;

	bat2_cell[0]=adc1_buf[BAT2_1]*adc_convert;
	bat2_cell[1]=adc1_buf[BAT2_2]*adc_convert;
	bat2_cell[2]=adc1_buf[BAT2_3]*adc_convert;
	bat2_cell[3]=adc1_buf[BAT2_4]*adc_convert;
	bat2_cell[4]=adc1_buf[BAT2_5]*adc_convert;
	bat2_cell[5]=adc1_buf[BAT2_6]*adc_convert;

	return;

}

int cell_count(){
	bool bat1=true;
	bool bat2=true;
	for (int i = 0; i = 5; i++) {
		if(bat1_cell[i] < 2.0){
			bat1=false;
		}
		if(bat2_cell[i] < 2.0){
			bat2=false;
		}
	}

	if (bat1 && bat2){
		return 12;
	}
	else if (bat1 || bat2){
		return 6;
	}
	else{
		return 0; //No battery -> Powersupply
	}

}

void get_voltage(){

	for (int i = 0; i = 5; i++) {
		if(bat1_cell[i] < 2.0){
			bat1_voltage =+ bat1_cell[i];
		}
		if(bat2_cell[i] < 2.0){
			bat2_voltage =+ bat2_cell[i];
		}

	}
}

void get_percentage(){
	//Discharge Curve for 6s Lipo
	float voltage_values[] = {25.2, 24.9, 24.67, 24.49, 24.14, 23.9, 23.72, 23.48, 23.25, 23.13, 23.01, 22.89, 22.77, 22.72, 22.6, 22.48, 22.36, 22.24, 22.12, 21.65, 19.64};
	int steps = 20;

	    for (int i = 0; i <= steps; i++) {
	    	if(bat1_voltage >= voltage_values[i]){
	    		battery1_percent = 100 - i * 5;
	    		break;
	    	}
	    }
	    for (int i = 0; i <= steps; i++) {
	    	if(bat2_voltage >= voltage_values[i]){
	    		battery2_percent = 100 - i * 5;
	    		break;
	    	}
	    }


	    if ((battery1_percent > 0)&&(battery2_percent > 0)){
	    	bat_percentage=(battery1_percent+battery2_percent)/2;
	    }
	    else if (battery1_percent > 0){
	    	bat_percentage=battery1_percent;
	    }
	    else if (battery2_percent > 0){
	    	bat_percentage=battery2_percent;
	    }
	    else{
	    	bat_percentage=101; //Powersupply
	    }


}





