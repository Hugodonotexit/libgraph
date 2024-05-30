CC=g++
CXXFLAGS=-Wall -std=c++20 -Ofast
INCLUDES=-I../

SRCS = test-0.cpp test-1.cpp test-2.cpp test-3.cpp test-4.cpp
OBJS = $(SRCS:.cpp=.o)
EXES = $(SRCS:.cpp=)

all: $(EXES)

%: %.o
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ $<

%.o: %.cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -rf *.gch *.o

clear: clean
	rm -rf $(EXES)