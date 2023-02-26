################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\cw32\随机抽取及按键抢答2\基于ch32v307随机点名及按键抢答2\Debug" -I"E:\cw32\随机抽取及按键抢答2\基于ch32v307随机点名及按键抢答2\Core" -I"E:\cw32\随机抽取及按键抢答2\基于ch32v307随机点名及按键抢答2\User" -I"E:\cw32\随机抽取及按键抢答2\基于ch32v307随机点名及按键抢答2\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

