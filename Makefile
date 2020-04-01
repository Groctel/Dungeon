HOME = .
BIN  = $(HOME)/bin
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncurses

all:
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(SRC)/dungeon.cpp -o $(BIN)/dungeon
