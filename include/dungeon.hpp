#ifndef DUNGEON_DUNGEON
#define DUNGEON_DUNGEON

#include <ncurses.h>
#include "player.hpp"
#include "ui.hpp"

typedef void (*fptr) ();

class Dungeon {
private:
	Player * player;
public:
	Dungeon  ();
	~Dungeon ();

	void MovePlayerUp    ();
	void MovePlayerDown  ();
	void MovePlayerLeft  ();
	void MovePlayerRight ();
};

#endif
