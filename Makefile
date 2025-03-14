CXX := g++
CXXFLAGS := -Wextra -Wall 

all: assignment3

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

assignment3: portfolio.o assignment3.o instruments.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o assignment3

.PHONY: clean all