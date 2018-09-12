################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/backend/interpreter/Executor.cpp 

OBJS += \
./wci/backend/interpreter/Executor.o 

CPP_DEPS += \
./wci/backend/interpreter/Executor.d 


# Each subdirectory must supply rules for building sources it contributes
wci/backend/interpreter/%.o: ../wci/backend/interpreter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


