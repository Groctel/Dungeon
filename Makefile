HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -g -Wall -I$(INC) -lncurses

all: directories controller dungeon ui
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/dungeon \
	                   $(OBJ)/controller.o \
	                   $(OBJ)/dungeon.o \
	                   $(OBJ)/log.o \
	                   $(OBJ)/player.o \
	                   $(OBJ)/ui.o

directories:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)

controller: dungeon player ui
	$(CXX) $(CXXFLAGS) $(SRC)/controller.cpp -c -o $(OBJ)/controller.o

dungeon: player ui
	$(CXX) $(CXXFLAGS) $(SRC)/dungeon.cpp -c -o $(OBJ)/dungeon.o

log:
	$(CXX) $(CXXFLAGS) $(SRC)/log.cpp -c -o $(OBJ)/log.o

player: log
	$(CXX) $(CXXFLAGS) $(SRC)/player.cpp -c -o $(OBJ)/player.o

ui: log
	$(CXX) $(CXXFLAGS) $(SRC)/ui.cpp -c -o $(OBJ)/ui.o
