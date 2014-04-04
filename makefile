#------------------------------------------------------------------------------
source=$(filter-out utMain%.cpp, $(wildcard *.cpp))
bin=eventdemo1 eventdemo2
CC=g++
#------------------------------------------------------------------------------
all: $(bin)

eventdemo%: $(source) utMain%.cpp
	$(CC) -std=c++11 $(source) utMain$*.cpp -o $@

clean:
	rm -f $(bin)

