HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncurses

all: dungeon
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/dungeon \
	                   $(OBJ)/dungeon.o $(OBJ)/player.o

dungeon: player
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC)/dungeon.cpp -c -o $(OBJ)/dungeon.o

player:
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC)/player.cpp -c -o $(OBJ)/player.o
