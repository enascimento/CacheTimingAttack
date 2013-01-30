################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/aes_attack.c \
../src/aes_core.c \
../src/alg.c \
../src/cache_evict.c \
../src/encrypt.c \
../src/key_revert.c \
../src/platform.c 

OBJS += \
./src/aes_attack.o \
./src/aes_core.o \
./src/alg.o \
./src/cache_evict.o \
./src/encrypt.o \
./src/key_revert.o \
./src/platform.o 

C_DEPS += \
./src/aes_attack.d \
./src/aes_core.d \
./src/alg.d \
./src/cache_evict.d \
./src/encrypt.d \
./src/key_revert.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze g++ compiler'
	mb-g++ -Wall -O0 -g3 -c -fmessage-length=0 -I../../empty_cpp_bsp_0/microblaze_0/include -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.00.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


