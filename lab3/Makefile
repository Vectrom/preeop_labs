CXX = g++
CXXFLAGS = -Wall -g
SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)
EXEC = ftest

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o $(EXEC)

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean run check
