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


ifeq($(PLATFORM),HOST)
PLATFORM_INCLUDES = ''
else
PLATFORM_INCLUDES = 
-i ./
endif


# Add your Source files to this variable
SOURCES = 
	main.c memory.c

# Add your include paths to this variable
INCLUDES =
	-i ./include/common \
	$(PLATFORM_INCLUDES)

	

