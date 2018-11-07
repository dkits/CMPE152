################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/pascal/parsers/ArrayTypeParser.cpp \
../wci/frontend/pascal/parsers/AssignmentStatementParser.cpp \
../wci/frontend/pascal/parsers/BlockParser.cpp \
../wci/frontend/pascal/parsers/CaseStatementParser.cpp \
../wci/frontend/pascal/parsers/CompoundStatementParser.cpp \
../wci/frontend/pascal/parsers/ConstantDefinitionsParser.cpp \
../wci/frontend/pascal/parsers/DeclarationsParser.cpp \
../wci/frontend/pascal/parsers/EnumerationTypeParser.cpp \
../wci/frontend/pascal/parsers/ExpressionParser.cpp \
../wci/frontend/pascal/parsers/ForStatementParser.cpp \
../wci/frontend/pascal/parsers/IfStatementParser.cpp \
../wci/frontend/pascal/parsers/RecordTypeParser.cpp \
../wci/frontend/pascal/parsers/RepeatStatementParser.cpp \
../wci/frontend/pascal/parsers/SimpleTypeParser.cpp \
../wci/frontend/pascal/parsers/StatementParser.cpp \
../wci/frontend/pascal/parsers/SubrangeTypeParser.cpp \
../wci/frontend/pascal/parsers/TypeDefinitionsParser.cpp \
../wci/frontend/pascal/parsers/TypeSpecificationParser.cpp \
../wci/frontend/pascal/parsers/VariableDeclarationsParser.cpp \
../wci/frontend/pascal/parsers/VariableParser.cpp \
../wci/frontend/pascal/parsers/WhileStatementParser.cpp 

OBJS += \
./wci/frontend/pascal/parsers/ArrayTypeParser.o \
./wci/frontend/pascal/parsers/AssignmentStatementParser.o \
./wci/frontend/pascal/parsers/BlockParser.o \
./wci/frontend/pascal/parsers/CaseStatementParser.o \
./wci/frontend/pascal/parsers/CompoundStatementParser.o \
./wci/frontend/pascal/parsers/ConstantDefinitionsParser.o \
./wci/frontend/pascal/parsers/DeclarationsParser.o \
./wci/frontend/pascal/parsers/EnumerationTypeParser.o \
./wci/frontend/pascal/parsers/ExpressionParser.o \
./wci/frontend/pascal/parsers/ForStatementParser.o \
./wci/frontend/pascal/parsers/IfStatementParser.o \
./wci/frontend/pascal/parsers/RecordTypeParser.o \
./wci/frontend/pascal/parsers/RepeatStatementParser.o \
./wci/frontend/pascal/parsers/SimpleTypeParser.o \
./wci/frontend/pascal/parsers/StatementParser.o \
./wci/frontend/pascal/parsers/SubrangeTypeParser.o \
./wci/frontend/pascal/parsers/TypeDefinitionsParser.o \
./wci/frontend/pascal/parsers/TypeSpecificationParser.o \
./wci/frontend/pascal/parsers/VariableDeclarationsParser.o \
./wci/frontend/pascal/parsers/VariableParser.o \
./wci/frontend/pascal/parsers/WhileStatementParser.o 

CPP_DEPS += \
./wci/frontend/pascal/parsers/ArrayTypeParser.d \
./wci/frontend/pascal/parsers/AssignmentStatementParser.d \
./wci/frontend/pascal/parsers/BlockParser.d \
./wci/frontend/pascal/parsers/CaseStatementParser.d \
./wci/frontend/pascal/parsers/CompoundStatementParser.d \
./wci/frontend/pascal/parsers/ConstantDefinitionsParser.d \
./wci/frontend/pascal/parsers/DeclarationsParser.d \
./wci/frontend/pascal/parsers/EnumerationTypeParser.d \
./wci/frontend/pascal/parsers/ExpressionParser.d \
./wci/frontend/pascal/parsers/ForStatementParser.d \
./wci/frontend/pascal/parsers/IfStatementParser.d \
./wci/frontend/pascal/parsers/RecordTypeParser.d \
./wci/frontend/pascal/parsers/RepeatStatementParser.d \
./wci/frontend/pascal/parsers/SimpleTypeParser.d \
./wci/frontend/pascal/parsers/StatementParser.d \
./wci/frontend/pascal/parsers/SubrangeTypeParser.d \
./wci/frontend/pascal/parsers/TypeDefinitionsParser.d \
./wci/frontend/pascal/parsers/TypeSpecificationParser.d \
./wci/frontend/pascal/parsers/VariableDeclarationsParser.d \
./wci/frontend/pascal/parsers/VariableParser.d \
./wci/frontend/pascal/parsers/WhileStatementParser.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/pascal/parsers/%.o: ../wci/frontend/pascal/parsers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -I"\Users\deric\Desktop\CMPE 152 Files\boost_1_68_0" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


