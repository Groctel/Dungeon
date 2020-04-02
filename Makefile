HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncurses

all: directories dungeon
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/dungeon \
	                   $(OBJ)/dungeon.o $(OBJ)/player.o $(OBJ)/log.o

directories:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)

dungeon: player
	$(CXX) $(CXXFLAGS) $(SRC)/dungeon.cpp -c -o $(OBJ)/dungeon.o

player: log
	$(CXX) $(CXXFLAGS) $(SRC)/player.cpp -c -o $(OBJ)/player.o

log:
	$(CXX) $(CXXFLAGS) $(SRC)/log.cpp -c -o $(OBJ)/log.o
