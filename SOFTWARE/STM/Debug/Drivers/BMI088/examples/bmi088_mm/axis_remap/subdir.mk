################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.c 

C_DEPS += \
./Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.d 

OBJS += \
./Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BMI088/examples/bmi088_mm/axis_remap/%.o Drivers/BMI088/examples/bmi088_mm/axis_remap/%.su: ../Drivers/BMI088/examples/bmi088_mm/axis_remap/%.c Drivers/BMI088/examples/bmi088_mm/axis_remap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-axis_remap

clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-axis_remap:
	-$(RM) ./Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.d ./Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.o ./Drivers/BMI088/examples/bmi088_mm/axis_remap/axis_remap.su

.PHONY: clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-axis_remap

