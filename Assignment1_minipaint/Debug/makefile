################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Assignment1_minipaint

# Tool invocations
Assignment1_minipaint: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
<<<<<<< HEAD
<<<<<<< HEAD
	g++  -o "Assignment1_minipaint" $(OBJS) $(USER_OBJS) $(LIBS)
=======
	g++ -L/System/Library/Frameworks/OpenGL.framework -L/opt/X11/lib -o "Assignment1_minipaint" $(OBJS) $(USER_OBJS) $(LIBS)
>>>>>>> origin/master
=======
	g++ -L"C:\Windows\System32\dll" -L"C:\MinGW\lib" -o "Assignment1_minipaint" $(OBJS) $(USER_OBJS) $(LIBS)
>>>>>>> origin/master
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) Assignment1_minipaint
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
