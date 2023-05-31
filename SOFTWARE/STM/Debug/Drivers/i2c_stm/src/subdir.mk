################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/i2c_stm/src/i2c_stm.c 

C_DEPS += \
./Drivers/i2c_stm/src/i2c_stm.d 

OBJS += \
./Drivers/i2c_stm/src/i2c_stm.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/i2c_stm/src/%.o Drivers/i2c_stm/src/%.su: ../Drivers/i2c_stm/src/%.c Drivers/i2c_stm/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lis3mdl/inc -I../Drivers/ROS/Battery/inc -I../Drivers/i2c_stm/inc -I../Drivers/Common -I../Drivers/BMI088/inc -I../Drivers/ROS/Status/inc -I../Drivers/ROS/Orientation/inc -I"../Drivers/ROS/Motor Driver/inc" -I../Drivers/ROS/LED/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-i2c_stm-2f-src

clean-Drivers-2f-i2c_stm-2f-src:
	-$(RM) ./Drivers/i2c_stm/src/i2c_stm.d ./Drivers/i2c_stm/src/i2c_stm.o ./Drivers/i2c_stm/src/i2c_stm.su

.PHONY: clean-Drivers-2f-i2c_stm-2f-src

