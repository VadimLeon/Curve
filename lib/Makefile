SHELL = /bin/sh

CXX = g++
CXXFLAGS := -std=c++17 -c -fPIC -I../include -pedantic-errors -Wall -Wextra -Werror -Wshadow -m64
LFLAG = -shared

TARGET = curve3D.dylib
SRCDIR = ../src
OBJDIR = ../obj

# C ++ source code which must be preprocessed.
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# The object file name for a source file
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking objects files..."
	$(CXX) $(LFLAG) -o $@ $^

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling..."
	$(CXX) -c $(CXXFLAGS) $< -o $@


cleanlib:
	rm -rf $(TARGET) $(OBJECTS)