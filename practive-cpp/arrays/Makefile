SRC_DIR := .

CXX = g++
CXXFLAGS += -std=c++14
LDFLAGS += -lgtest -pthread 


all: test clean

test: vectortest.o jvector.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

jvector.o: jvector.cpp
	$(CXX) $(CXXFLAGS) -c $<

vectortest.o: vectortest.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY:clean
clean: 
	rm *.o
