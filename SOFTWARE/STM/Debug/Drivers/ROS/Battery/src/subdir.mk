################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/ROS/Battery/src/battery_node.cpp 

OBJS += \
./Drivers/ROS/Battery/src/battery_node.o 

CPP_DEPS += \
./Drivers/ROS/Battery/src/battery_node.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ROS/Battery/src/%.o Drivers/ROS/Battery/src/%.su: ../Drivers/ROS/Battery/src/%.cpp Drivers/ROS/Battery/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BMI088/inc -I../Drivers/lis3mdl/inc -I../Drivers/ROS/Battery/inc -I../Drivers/i2c_stm/inc -I../Drivers/ROS/LED/inc -I"../Drivers/ROS/Motor Driver/inc" -I../Drivers/ROS/Status/inc -I../Drivers/ROS/Orientation/inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ROS-2f-Battery-2f-src

clean-Drivers-2f-ROS-2f-Battery-2f-src:
	-$(RM) ./Drivers/ROS/Battery/src/battery_node.d ./Drivers/ROS/Battery/src/battery_node.o ./Drivers/ROS/Battery/src/battery_node.su

.PHONY: clean-Drivers-2f-ROS-2f-Battery-2f-src

