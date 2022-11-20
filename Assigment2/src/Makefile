#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# this is 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 		%.i
# 		%.asm
# 		%.o
# 		compile-all #generate obj files but don't link or create output
# 		build
# 		clean
#
# Platform Overrides:
# 		HOST - this the output file to run the code on the native system. 
#		MSP432 - this is to output the files for the MSP432 dev board for the class.  
#		
#
#------------------------------------------------------------------------------
include sources.mk


PLATFORM = HOST
CC = gcc
ARCH = $(shell arch)
CPU = x86-64
SPECS = sys.nospecs



# if our platform is host, use gcc, else use cross compiler


ifeq($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc 
	CPU = cortex-m4 
	ARCH = thumb
	SPECS = sys.nospecs
endif


OUTPUT_DIR = ./output/$(PLATFORM)/
OBJS:=$(SOURCES:.c=.o)
ASMS:=$(SOURCES:.c=.asm)
PREPS:=$(SOURCES:.c=.i)
# Compiler Flags and Defines

LD = 
LDFLAGS = 
#common to all platforms
PLATFORM_FLAGS := -m$(ARCH) -mcpu=$(CPU) -arch=$(ARCH) --specs=$(SPECS)
CFLAGS =  -g -Werror -Wall -O0 -std=c99 $(INCLUDES) 
CPPFLAGs = 



%.i : %.c
	$(CC) -c  $@ -o $(OUTPUT_DIR)$< -E $(CFLAGS) 

%.asm : %.c
	$(CC) -c $@ -o $(OUTPUT_DIR)$< -E $(CFLAGS)  

compile-all: $(SOURCES)
	$(CC) $(CFLAGS) -MM -map=$(OUTPUT_DIR)c1m2.map -o $(OUTPUT_DIR)c1m2.out 




.PHONY clean
#delete everything in my output dir
clean:
	rm -r $(OUTPUT_DIR)

