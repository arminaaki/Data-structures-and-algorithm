CC = g++
CFLAGS= -std=c++
LDFLAGS = 
SOURCES = Driver.cpp Graph.cpp UnionFind.cpp Edge.cpp
DEPS = Graph.h UnionFind.h Edge.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = prog2
CXX_FLAGS = -std=c++0x

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: $.cpp $(DEPS)
	$(CC) $(CFLAGS) *.cp

clean: 
	rm prog2
	rm *.o
