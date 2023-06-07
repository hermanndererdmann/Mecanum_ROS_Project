/*
 * i2c_arduino.cpp
 *
 *  Created on: 11.10.2021
 *  Author: Jan Schuessler, FHGR
 *  Board: Gscheiduino
 *  Description: i2c driver
 */
#include "i2c_stm.h"

extern I2C_HandleTypeDef hi2c1;
HAL_StatusTypeDef ret;

int i2cWrite(uint8_t DevAddress, uint8_t reg, uint8_t data) {
	/*
	 * writes one byte 'data' to register 'reg'
	 */
	uint8_t buf[2];
	buf[0] = reg;
	buf[1] = data;
	ret = HAL_I2C_Master_Transmit(&hi2c1, DevAddress, buf, 2, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C write Error\r\n");
		return 1;
	} else {
		//printf("I2C wrote successfully\r\n");
		return 0;
	}
}

int i2cRead(uint8_t DevAddress, uint8_t reg, uint8_t *data, uint8_t size) {
	/*
	 * reads 'size' registers, starting from register 'reg', stores bytes in 'data'
	 */
	data[0] = reg;
	ret = HAL_I2C_Master_Transmit(&hi2c1, DevAddress, data, 1, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C read (write) Error\r\n");
		return 1;
	}
	ret = HAL_I2C_Master_Receive(&hi2c1, DevAddress, data, size, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C read (read) Error\r\n");
		return 1;
	}
	return 0;
}
