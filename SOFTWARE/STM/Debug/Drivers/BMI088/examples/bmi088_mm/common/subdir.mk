################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BMI088/examples/bmi088_mm/common/common.c 

C_DEPS += \
./Drivers/BMI088/examples/bmi088_mm/common/common.d 

OBJS += \
./Drivers/BMI088/examples/bmi088_mm/common/common.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BMI088/examples/bmi088_mm/common/%.o Drivers/BMI088/examples/bmi088_mm/common/%.su: ../Drivers/BMI088/examples/bmi088_mm/common/%.c Drivers/BMI088/examples/bmi088_mm/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-common

clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-common:
	-$(RM) ./Drivers/BMI088/examples/bmi088_mm/common/common.d ./Drivers/BMI088/examples/bmi088_mm/common/common.o ./Drivers/BMI088/examples/bmi088_mm/common/common.su

.PHONY: clean-Drivers-2f-BMI088-2f-examples-2f-bmi088_mm-2f-common
