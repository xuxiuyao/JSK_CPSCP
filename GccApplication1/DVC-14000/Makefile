################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../inc \
../src


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/command.c \
../src/key.c \
../src/led.c \
../src/main.c \
../src/manager.c \
../src/remote.c \
../src/status.c \
../src/timer.c \
../src/Title.c \
../src/usart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/command.o \
src/key.o \
src/led.o \
src/main.o \
src/manager.o \
src/remote.o \
src/status.o \
src/timer.o \
src/Title.o \
src/usart.o

OBJS_AS_ARGS +=  \
src/command.o \
src/key.o \
src/led.o \
src/main.o \
src/manager.o \
src/remote.o \
src/status.o \
src/timer.o \
src/Title.o \
src/usart.o

C_DEPS +=  \
src/command.d \
src/key.d \
src/led.d \
src/main.d \
src/manager.d \
src/remote.d \
src/status.d \
src/timer.d \
src/Title.d \
src/usart.d

C_DEPS_AS_ARGS +=  \
src/command.d \
src/key.d \
src/led.d \
src/main.d \
src/manager.d \
src/remote.d \
src/status.d \
src/timer.d \
src/Title.d \
src/usart.d

OUTPUT_FILE_PATH +=CAMcontrol.elf

OUTPUT_FILE_PATH_AS_ARGS +=CAMcontrol.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





















src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -D_PRODUCT_TYPE_CODE=_DVC_14000 -DF_CPU=8000000UL  -I"../inc"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -mmcu=atmega168pa -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="CAMcontrol.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega168pa  
	@echo Finished building target: $@
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "CAMcontrol.elf" "CAMcontrol.hex"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "CAMcontrol.elf" "CAMcontrol.eep" || exit 0
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "CAMcontrol.elf" > "CAMcontrol.lss"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "CAMcontrol.elf" "CAMcontrol.srec"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "CAMcontrol.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "CAMcontrol.elf" "CAMcontrol.a" "CAMcontrol.hex" "CAMcontrol.lss" "CAMcontrol.eep" "CAMcontrol.map" "CAMcontrol.srec" "CAMcontrol.usersignatures"
	