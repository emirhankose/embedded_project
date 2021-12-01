################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Lenovo/STM32CubeIDE/workspace_1.7.0/embedded/stm32g0-main/include/startup_stm32g031k8tx.s 

C_SRCS += \
../bsp.c \
../main.c \
C:/Users/Lenovo/STM32CubeIDE/workspace_1.7.0/embedded/stm32g0-main/include/system_stm32g0xx.c 

OBJS += \
./bsp.o \
./main.o \
./startup_stm32g031k8tx.o \
./system_stm32g0xx.o 

S_DEPS += \
./startup_stm32g031k8tx.d 

C_DEPS += \
./bsp.d \
./main.d \
./system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
startup_stm32g031k8tx.o: C:/Users/Lenovo/STM32CubeIDE/workspace_1.7.0/embedded/stm32g0-main/include/startup_stm32g031k8tx.s subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
system_stm32g0xx.o: C:/Users/Lenovo/STM32CubeIDE/workspace_1.7.0/embedded/stm32g0-main/include/system_stm32g0xx.c subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

