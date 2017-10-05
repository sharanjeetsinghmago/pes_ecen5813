#------------------------------------------------------------------------------
# This makefile is for build system supporting three platforms HOST (Host PC),
# BBB (Beagle Bone Black) and KL25Z (Freedom board)
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      
#		<FILE>.i - Generaates <FILE>.i preprocessed file
#		<FILE>.asm - Generates <FILE>.asm assembly file 
#		<FILE>.o - Generates <FILE>.o object file without linking
#		compile-all - Compliles all object files without linking
#		build : Compiles all object files  and links into a final executable
#		clean : Removes all generated files
#
# Platform Overrides:
#		PLATFORM - Target platform (HOST, BBB , KL25Z)
#
#------------------------------------------------------------------------------

# Include file
include sources.mk

# Project call macro
PROJECT = PROJECT1

# Target filename
TARGET = project1

# Debug print macro
# To enable - define VERBOSE
PRINT = VERBOSE

# Default platform HOST
PLATFORM = HOST

# Linker file for KL25Z
LINKER_FILE = ../platform/MKL25Z128xxx4_flash.ld

# Architecture specific details (KL25Z)
CPU = cortex-m0plus
ARCH = armv6-m
#software floating point
FLOAT_ABI = soft			
FPU = fpv4-sp-d16
SPECS = nosys.specs 

ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = ld
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)
	CPPFLAGS = -DHOST -D$(PROJECT) -D$(PRINT)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJECTS = $(SOURCES:.c=.o)
	DEPS = $(SOURCES:.c=.d)
	#Berkely size format in decimal
	SIZE = size -Bd
	LIB_OBJS = $(LIB_SRCS:.c=.o)
else
	ifeq ($(PLATFORM),KL25Z)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) \
				 -mthumb -march=$(ARCH) -mfloat-abi=$(FLOAT_ABI) \
				 -mfpu=$(FPU) --specs=$(SPECS) $(INCLUDES_K)
		CPPFLAGS = -DKL25Z -D$(PROJECT) -D$(PRINT)
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
		OBJECTS = $(SOURCES_K:.c=.o) startup_MKL25Z4.o
		DEPS = $(SOURCES_K:.c=.d) 
		SIZE = arm-none-eabi-size -Bd
		LIB_OBJS = $(LIB_SRCS_K:.c=.o)

	else
		CC = arm-linux-gnueabi-gcc
		LD = arm-linux-gnueabi-ld
		CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)
		CPPFLAGS = -DBBB -D$(PROJECT) -D$(PRINT)
		LDFLAGS = -Wl,-Map=$(TARGET).map
		OBJECTS = $(SOURCES:.c=.o)
		DEPS = $(SOURCES:.c=.d)
		SIZE = arm-linux-gnueabi-size -Bd
		LIB_OBJS = $(LIB_SRCS:.c=.o)

	endif
endif

# Preprocessed files
%.i : %.c
	@echo "GENERATING PRE-PROCESSED FILE..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

# Assembly files
%.asm : %.c
	@echo "GENERATING ASSEMBLY FILE..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

# Output files
%.o : %.c 
	@echo "GENERATING OBJECT FILE..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Dependency files
%.d : %.c
	@echo "GENERATING DEPENDENCY FILE..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -M $< -o $@ 

# PHONY protection
.PHONY : compile-all build clean

# Compile all object files
compile-all : $(OBJECTS)
	@echo ""
	@echo "COMPILED ALL SOURCE FILES BUT NOT LINKED" 

# Compile and link into final executable
build : $(OBJECTS) $(DEPS)
	@echo ""
	@echo "LINKING AND GENERATING FINAL EXECUTABLE..."
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJECTS) -o $(TARGET).elf
	@echo "BUILDING ARCHIVE FILE"
	ar rc lib$(TARGET).a $(LIB_OBJS)
	@echo ""
	@echo "-------------------------------------------------------"
	@echo "   BUILD REPORT OF CODE SIZE (BYTES)"
	@echo "-------------------------------------------------------"
	$(SIZE) $(TARGET).elf
	@echo "-------------------------------------------------------"


# Remove generated files
clean : 
	rm -rf $(TARGET).elf  $(TARGET).map *.o *.asm *.i *.d *.a
	@echo "GENERATED FILES REMOVED..."





