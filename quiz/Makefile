SRC := $(wildcard *.cc)
TAR := $(SRC:%.cc=%)
CXXFLAGS := -Og -std=c++11 -I.. -Wall -Wextra -pthread

all: $(TAR)

%: %.cc
	$(CXX) -o bin/$@ $< $(CXXFLAGS)