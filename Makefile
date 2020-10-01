HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncursesw

.PHONY: all docs clean directories debug

all: directories $(BIN)/dungeon docs

debug: CXXFLAGS = -std=c++11 -g -Og -Wall -I$(INC) -lncursesw
debug: clean all


directories:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)
	@mkdir -p $(DOC)

$(BIN)/dungeon: $(OBJ)/controller.o $(OBJ)/dungeon.o $(OBJ)/log.o \
		$(OBJ)/player.o $(OBJ)/ui.o $(OBJ)/main.o 
	$(CXX) $(CXXFLAGS) $^ -o $@


$(OBJ)/controller.o: $(SRC)/controller.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

$(OBJ)/dungeon.o: $(SRC)/dungeon.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

$(OBJ)/log.o: $(SRC)/log.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

$(OBJ)/player.o: $(SRC)/player.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

$(OBJ)/ui.o: $(SRC)/ui.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@
	
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

docs:
	@rm -rf $(DOC)/*
	@printf "Creating documentation in \"%s\"...\n" $(DOC)
	@doxygen 1>/dev/null 2>&1


clean:
	-rm $(OBJ)/*.o
	-rm $(BIN)/dungeon
