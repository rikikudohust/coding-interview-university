SRC_DIR :=.

CXX = g++
CXXFLAGS = -std=c++14
LDFLAGS += -lgtest -pthread

all: test

test: linkedlisttest.o linkedlist.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

linkedlist.o: linkedlist.cpp
	$(CXX) $(CXXFLAGS) -c $< 

linkedlisttest.o: linkedlisttest.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o test
