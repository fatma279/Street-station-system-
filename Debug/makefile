################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIMER_DRV/subdir.mk
-include SevenSegment/subdir.mk
-include PWM_DRV/subdir.mk
-include LCD_DRV/subdir.mk
-include DIO_DRV/subdir.mk
-include App/subdir.mk
-include ADC_DRV/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Street_stastion_system.lss \

FLASH_IMAGE += \
Street_stastion_system.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Street_stastion_system.elf secondary-outputs

# Tool invocations
Street_stastion_system.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Street_stastion_system.map -mmcu=atmega32 -o "Street_stastion_system.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Street_stastion_system.lss: Street_stastion_system.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Street_stastion_system.elf  >"Street_stastion_system.lss"
	@echo 'Finished building: $@'
	@echo ' '

Street_stastion_system.hex: Street_stastion_system.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Street_stastion_system.elf  "Street_stastion_system.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Street_stastion_system.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Street_stastion_system.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Street_stastion_system.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
