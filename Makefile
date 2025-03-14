CXX := g++
CXXFLAGS := -Wextra -Wall -std=c++23

all: assignment3

portfolio.o: portfolio.cc portfolio.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

assignment3.o: assignment3.cc instruments.h portfolio.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

assignment3: portfolio.o assignment3.o instruments.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o assignment3

.PHONY: clean