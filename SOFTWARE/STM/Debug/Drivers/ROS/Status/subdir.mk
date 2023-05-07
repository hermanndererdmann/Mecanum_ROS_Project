################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/ROS/Status/status.cpp 

OBJS += \
./Drivers/ROS/Status/status.o 

CPP_DEPS += \
./Drivers/ROS/Status/status.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ROS/Status/%.o Drivers/ROS/Status/%.su: ../Drivers/ROS/Status/%.cpp Drivers/ROS/Status/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ROS-2f-Status

clean-Drivers-2f-ROS-2f-Status:
	-$(RM) ./Drivers/ROS/Status/status.d ./Drivers/ROS/Status/status.o ./Drivers/ROS/Status/status.su

.PHONY: clean-Drivers-2f-ROS-2f-Status

