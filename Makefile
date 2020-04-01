HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncurses

all: player
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(SRC)/dungeon.cpp -o $(BIN)/dungeon \
	                   $(OBJ)/player.o

player:
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC)/player.cpp -c -o $(OBJ)/player.o
