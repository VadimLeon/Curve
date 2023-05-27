#-----------------------------------------------------------------------------#
#  ENVIRONMENT                                                                #
#-----------------------------------------------------------------------------#

# To avoid trouble on systems where the SHELL variable might be inherited from
# the environment.
SHELL = /bin/sh

# Program for compiling C++ programs; default ‘g++’.
CXX = g++-13

# Extra flags to give to the C++ compiler.
# -std: standard
# -Iinclude: Adds ‘./include‘ directory with header files.
# -pedantic-errors: Issue all the errors demanded by strict ISO C and ISO C++.
# -Wall: Enables all the warnings about constructions.
# -Wextra: Enables some extra warning flags that are not enabled by -Wall.
# -Wshadow: Warn whenever a local variable shadows another local variable,
#           parameter or global variable or a built-in function is shadowed.
# -fopenmp: Enable OpenMP support.
# -m64: Generate code for a 64-bit environment.
CXXFLAGS := -std=c++17 -Iinclude -fopenmp -pedantic-errors -Wall -Wextra -Werror -Wshadow -m64

# Extra flags to give to compilers when they are supposed to invoke the linker,
# ‘ld’, such as -L. Libraries (-lfoo) should be added to the LDLIBS variable
# instead.
LDFLAGS = -Llib

# Library flags or names given to compilers when they are supposed to invoke
# the linker, ‘ld’. Non-library linker flags, such as -L, should go in the
# LDFLAGS variable.
LDLIBS := #-lcurve3D#-lstdc++ -lm

# Create directory if it doesn't exist.
MKDIR_P = mkdir -p


#-----------------------------------------------------------------------------#
#  EXECUTABLE, SOURCES, OBJECTS AND PROJECT STRUCTURE                         #
#-----------------------------------------------------------------------------#

# Project structure
SRCDIR = src
OBJDIR = obj
BINDIR = bin
#DOCDIR = doc
#LIBDIR = lib
#DATADIR    = resources
#SCRIPTSDIR = scripts
#TESTSDIR   = tests

# Executable
TARGET = $(BINDIR)/curve

# C ++ source code which must be preprocessed.
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# By default, the object file name for a source file is made by replacing the
# suffix .c, .cpp, .i, .s, etc., with .o.
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


#-----------------------------------------------------------------------------#
#  RECIPES                                                                    #
#-----------------------------------------------------------------------------#

# A phony target is one that is not really the name of a file; rather it is
# just a name for a recipe to be executed when you make an explicit request.
.PHONY: all build clean debug release

# Make all the top-level targets the makefile knows about.
all: build $(TARGET)

# The rule that links libraries to the target.
# -o outfile: Place output in file outfile. If -o is not specified, the default
#             is to put an executable file in a.out.
# $@: The file name of the target.
# $^: The names of all the prerequisites, with spaces between them.
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "Copying target to project directory..."
	cp $(TARGET) curve

# The rule that compiles ‘.cpp’ files into ‘.o’ files.
# The recipe uses the automatic variables ‘$@’ and ‘$<’ to substitute the names
# of the target file and the source file in each case where the rule applies.
# $@: The file name of the target.
# $<: The name of the first prerequisite.
$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling..."
	$(CXX) -c $(CXXFLAGS) $< -o $@

# When a line starts with ‘@’, the echoing of that line is suppressed. The ‘@’
# is discarded before the line is passed to the shell. Typically you would use
# this for a command whose only effect is to print something, such as an echo
# command to indicate progress through the makefile.
build:
	@$(MKDIR_P) $(BINDIR)
	@$(MKDIR_P) $(OBJDIR)
#	@$(MKDIR_P) $(LIBDIR)
#	@$(MKDIR_P) $(DATADIR)
#	@$(MKDIR_P) $(SCRIPTSDIR)
#	@$(MKDIR_P) $(TESTSDIR)

# -g: Produce debugging information in the operating system's native format.
debug: CXXFLAGS += -DDEBUG -g
debug: all

# -O0: Reduce compilation time and make debugging produce the expected results.
#      This is the default.
# -O1: Optimize. Optimizing compilation takes somewhat more time, and a lot
#      more memory for a large function.
# -O2: Optimization flag. GCC performs nearly all supported optimizations that
#      do not involve a space-speed tradeoff.
# -O3: Optimize even more. -O3 turns on all optimizations specified by -O2 and
#      also turns on other optimization flags.
# -Os: Optimize for size. -Os enables all -O2 optimizations that do not
#      typically increase code size. It also performs further optimizations
#      designed to reduce code size.
release: CXXFLAGS += -O2
release: all

# Delete all files (and directories) that are normally created by running make.
clean:
	@echo "Cleaning..."
	rm -f $(OBJECTS) $(TARGET) ./curve