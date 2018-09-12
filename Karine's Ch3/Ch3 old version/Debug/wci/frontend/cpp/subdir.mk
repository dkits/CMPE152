################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/cpp/CppError.cpp \
../wci/frontend/cpp/CppErrorHandler.cpp \
../wci/frontend/cpp/CppParserTD.cpp \
../wci/frontend/cpp/CppScanner.cpp \
../wci/frontend/cpp/CppToken.cpp 

OBJS += \
./wci/frontend/cpp/CppError.o \
./wci/frontend/cpp/CppErrorHandler.o \
./wci/frontend/cpp/CppParserTD.o \
./wci/frontend/cpp/CppScanner.o \
./wci/frontend/cpp/CppToken.o 

CPP_DEPS += \
./wci/frontend/cpp/CppError.d \
./wci/frontend/cpp/CppErrorHandler.d \
./wci/frontend/cpp/CppParserTD.d \
./wci/frontend/cpp/CppScanner.d \
./wci/frontend/cpp/CppToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/cpp/%.o: ../wci/frontend/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


