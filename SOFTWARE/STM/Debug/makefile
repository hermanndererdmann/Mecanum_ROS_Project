################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/i2c_stm/src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/ROS/Status/subdir.mk
-include Drivers/ROS/Motor\ Driver/subdir.mk
-include Drivers/ROS/LED/subdir.mk
-include Drivers/ROS/Battery/subdir.mk
-include Drivers/BMI088/examples/bmi08x/read_synchronized_data_mcu/subdir.mk
-include Drivers/BMI088/examples/bmi08x/read_sensor_data/subdir.mk
-include Drivers/BMI088/examples/bmi08x/polling_streaming_pc/subdir.mk
-include Drivers/BMI088/examples/bmi08x/interrupt_streaming_pc/subdir.mk
-include Drivers/BMI088/examples/bmi08x/gyro_fifo_watermark/subdir.mk
-include Drivers/BMI088/examples/bmi08x/gyro_fifo_full/subdir.mk
-include Drivers/BMI088/examples/bmi08x/common/subdir.mk
-include Drivers/BMI088/examples/bmi08x/accel_fifo_watermark/subdir.mk
-include Drivers/BMI088/examples/bmi08x/accel_fifo_full/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/read_sensor_data/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/orientation/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/no_motion/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/low_g/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/high_g/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/gyro_fifo_watermark/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/gyro_fifo_full/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/data_sync_mcu/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/common/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/axis_remap/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/any_motion/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/accel_fifo_watermark/subdir.mk
-include Drivers/BMI088/examples/bmi088_mm/accel_fifo_full/subdir.mk
-include Drivers/BMI088/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Inc/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ROS_MR2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ROS_MR2.elf \

MAP_FILES += \
ROS_MR2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ROS_MR2.list \


# All Target
all: main-build

# Main-build Target
main-build: ROS_MR2.elf secondary-outputs

# Tool invocations
ROS_MR2.elf ROS_MR2.map: $(OBJS) $(USER_OBJS) C:\Users\flori\OneDrive\ -\ FH\ Graubünden\Desktop\ROS\ PROJEKT\SOFTWARE\STM\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "ROS_MR2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\flori\OneDrive - FH Graubünden\Desktop\ROS PROJEKT\SOFTWARE\STM\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ROS_MR2.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ROS_MR2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ROS_MR2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ROS_MR2.elf ROS_MR2.list ROS_MR2.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
