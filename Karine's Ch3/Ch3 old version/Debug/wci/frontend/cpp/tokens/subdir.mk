################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/cpp/tokens/CppErrorToken.cpp \
../wci/frontend/cpp/tokens/CppNumberToken.cpp \
../wci/frontend/cpp/tokens/CppSpecialSymbolToken.cpp \
../wci/frontend/cpp/tokens/CppStringToken.cpp \
../wci/frontend/cpp/tokens/CppWordToken.cpp 

OBJS += \
./wci/frontend/cpp/tokens/CppErrorToken.o \
./wci/frontend/cpp/tokens/CppNumberToken.o \
./wci/frontend/cpp/tokens/CppSpecialSymbolToken.o \
./wci/frontend/cpp/tokens/CppStringToken.o \
./wci/frontend/cpp/tokens/CppWordToken.o 

CPP_DEPS += \
./wci/frontend/cpp/tokens/CppErrorToken.d \
./wci/frontend/cpp/tokens/CppNumberToken.d \
./wci/frontend/cpp/tokens/CppSpecialSymbolToken.d \
./wci/frontend/cpp/tokens/CppStringToken.d \
./wci/frontend/cpp/tokens/CppWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/cpp/tokens/%.o: ../wci/frontend/cpp/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


