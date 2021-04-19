SRC_DIR := .

CXX = g++
CXXFLAGS += -std=c++14
LDFLAGS += -lgtest -pthread

all: test

test: queue.o queuetest.o
	$(CXX) $(CXXFLAGS) -g $@ $^ $(LDFLAGS)

queue.o: queue.cpp
	$(CXX) $(CXXFLAGS) -c $<	

queuetest.o: queuetest.cpp
	$(CXX) $(CXXFLAGS) -c $<	

.PHONY: clean
clean:
	rm *.o test	
