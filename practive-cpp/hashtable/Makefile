SRC_DIR := .

CXX = g++
CXXFLAGS += -std=c++14
LDFLAGS += -lgtest -pthread

all: test

test: hashtable.o hashtabletest.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

hashtable.o: hashtable.cpp
	$(CXX) $(CXXFLAGS) -c $<

hashtabletest.o: hashtabletest.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY:clean
clean:
	rm test *.o
