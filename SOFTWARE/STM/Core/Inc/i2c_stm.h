/*
 * i2c_stm.h
 *
 *  Created on: Oct 18, 2022
 *      Author: schuessleja1
 */

#ifndef I2C_STM_INC_I2C_STM_H_
#define I2C_STM_INC_I2C_STM_H_

#include <main.h>

int i2cWrite(uint8_t DevAddress, uint8_t reg, uint8_t data);

int i2cRead(uint8_t DevAddress, uint8_t reg, uint8_t *data, uint8_t size);


#endif /* I2C_STM_INC_I2C_STM_H_ */
