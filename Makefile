TARGET = main.out
OBJS = main.o

CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11

.SUFFIXES: .c .o

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $^

.c.o:
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)

main.o: simple_percept.hpp
