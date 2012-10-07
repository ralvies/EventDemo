#------------------------------------------------------------------------------
source=$(filter-out utMain%.cpp, $(wildcard *.cpp))
bin=eventdemo1 eventdemo2
includes=./boost-1.47.0/include/boost/tr1/tr1 ./boost-1.47.0/include
CC=g++
#------------------------------------------------------------------------------
all: $(bin)

eventdemo%: $(source) utMain%.cpp
	$(CC) $(patsubst %,-I%,$(includes)) $(source) utMain$*.cpp -o $@

clean:
	rm -f $(bin)

