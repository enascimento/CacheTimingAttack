################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
aes_cache_timing.elf.size \

ELFCHECK += \
aes_cache_timing.elf.elfcheck \


# All Target
all: aes_cache_timing.elf secondary-outputs

# Tool invocations
aes_cache_timing.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MicroBlaze g++ linker'
	mb-g++ -Wl,-T -Wl,../src/lscript.ld -L../../empty_cpp_bsp_0/microblaze_0/lib -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.00.b -mno-xl-soft-mul -o"aes_cache_timing.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

aes_cache_timing.elf.size: aes_cache_timing.elf
	@echo 'Invoking: MicroBlaze Print Size'
	mb-size aes_cache_timing.elf  |tee "aes_cache_timing.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

aes_cache_timing.elf.elfcheck: aes_cache_timing.elf
	@echo 'Invoking: Xilinx ELF Check'
	elfcheck aes_cache_timing.elf -hw C:/Users/caw/Projects/CacheTimingAttack/xps/SDK/SDK_Workspace_35/hw_platform_0/system.xml -pe microblaze_0  |tee "aes_cache_timing.elf.elfcheck"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(ELFSIZE)$(CXX_DEPS)$(C_UPPER_DEPS)$(ELFCHECK)$(S_UPPER_DEPS) aes_cache_timing.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
