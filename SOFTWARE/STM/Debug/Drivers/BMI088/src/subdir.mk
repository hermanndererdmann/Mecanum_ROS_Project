################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BMI088/src/bmi088_mma.c \
../Drivers/BMI088/src/bmi08a.c \
../Drivers/BMI088/src/bmi08g.c \
../Drivers/BMI088/src/bmi08xa.c \
../Drivers/BMI088/src/common.c \
../Drivers/BMI088/src/read_sensor_data.c 

C_DEPS += \
./Drivers/BMI088/src/bmi088_mma.d \
./Drivers/BMI088/src/bmi08a.d \
./Drivers/BMI088/src/bmi08g.d \
./Drivers/BMI088/src/bmi08xa.d \
./Drivers/BMI088/src/common.d \
./Drivers/BMI088/src/read_sensor_data.d 

OBJS += \
./Drivers/BMI088/src/bmi088_mma.o \
./Drivers/BMI088/src/bmi08a.o \
./Drivers/BMI088/src/bmi08g.o \
./Drivers/BMI088/src/bmi08xa.o \
./Drivers/BMI088/src/common.o \
./Drivers/BMI088/src/read_sensor_data.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BMI088/src/%.o Drivers/BMI088/src/%.su: ../Drivers/BMI088/src/%.c Drivers/BMI088/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lis3mdl/inc -I../Drivers/ROS/Battery/inc -I../Drivers/i2c_stm/inc -I../Drivers/Common -I../Drivers/BMI088/inc -I../Drivers/ROS/Status/inc -I../Drivers/ROS/Orientation/inc -I"../Drivers/ROS/Motor Driver/inc" -I../Drivers/ROS/LED/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BMI088-2f-src

clean-Drivers-2f-BMI088-2f-src:
	-$(RM) ./Drivers/BMI088/src/bmi088_mma.d ./Drivers/BMI088/src/bmi088_mma.o ./Drivers/BMI088/src/bmi088_mma.su ./Drivers/BMI088/src/bmi08a.d ./Drivers/BMI088/src/bmi08a.o ./Drivers/BMI088/src/bmi08a.su ./Drivers/BMI088/src/bmi08g.d ./Drivers/BMI088/src/bmi08g.o ./Drivers/BMI088/src/bmi08g.su ./Drivers/BMI088/src/bmi08xa.d ./Drivers/BMI088/src/bmi08xa.o ./Drivers/BMI088/src/bmi08xa.su ./Drivers/BMI088/src/common.d ./Drivers/BMI088/src/common.o ./Drivers/BMI088/src/common.su ./Drivers/BMI088/src/read_sensor_data.d ./Drivers/BMI088/src/read_sensor_data.o ./Drivers/BMI088/src/read_sensor_data.su

.PHONY: clean-Drivers-2f-BMI088-2f-src

