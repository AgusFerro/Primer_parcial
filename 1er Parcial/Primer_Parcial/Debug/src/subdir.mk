################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/Informes.c \
../src/Inputs.c \
../src/Pedido.c \
../src/Primer_Parcial.c \
../src/Validaciones.c 

OBJS += \
./src/Cliente.o \
./src/Informes.o \
./src/Inputs.o \
./src/Pedido.o \
./src/Primer_Parcial.o \
./src/Validaciones.o 

C_DEPS += \
./src/Cliente.d \
./src/Informes.d \
./src/Inputs.d \
./src/Pedido.d \
./src/Primer_Parcial.d \
./src/Validaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


