################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
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
Propeller\ LED\ Clock.lss \

FLASH_IMAGE += \
Propeller\ LED\ Clock.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Propeller\ LED\ Clock.elf secondary-outputs

# Tool invocations
Propeller\ LED\ Clock.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Propeller LED Clock.map -mmcu=atmega32 -o "Propeller LED Clock.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Propeller\ LED\ Clock.lss: Propeller\ LED\ Clock.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Propeller LED Clock.elf  >"Propeller LED Clock.lss"
	@echo 'Finished building: $@'
	@echo ' '

Propeller\ LED\ Clock.hex: Propeller\ LED\ Clock.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Propeller LED Clock.elf  "Propeller LED Clock.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Propeller\ LED\ Clock.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Propeller LED Clock.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "Propeller LED Clock.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
