# Compiler and flags
CC = g++
CXXFLAGS = -Wall -std=c++20 -Ofast
LDFLAGS = -L/usr/lib -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image
INCLUDES = -I/usr/include/SDL2 -I../

# Source files and corresponding object files
SRCS = test-0.cpp test-1.cpp test-2.cpp
OBJS = $(SRCS:.cpp=.o)
EXES = $(SRCS:.cpp=)

# Default target
all: $(EXES)

# Rule to build the executables from object files
$(EXES): % : %.o
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

# Rule to build object files from source files
%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Clean up
.PHONY: clean
clean:
	rm -rf *.o $(EXES)