SRC_DIR = .
CXX = g++
CXXFLAGS += -std=c++14
LDFLAGS += -lgtest -pthread

all: test

test: test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.Phony:clean
clean: 
	rm *.o
