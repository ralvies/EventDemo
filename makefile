#------------------------------------------------------------------------------
source=$(filter-out utMain%.cpp, $(wildcard *.cpp))
bin=eventdemo1 eventdemo2
CC=g++
#------------------------------------------------------------------------------
all: $(bin)

eventdemo%: $(source) utMain%.cpp
	$(CC) -O3 -std=c++17 $(source) utMain$*.cpp -o $@

clean:
	rm -f $(bin)

