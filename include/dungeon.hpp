#ifndef DUNGEON_DUNGEON
#define DUNGEON_DUNGEON

#include <ncurses.h>
#include "player.hpp"

typedef void (*fptr) ();

class Dungeon {
private:
	bool running;
	int key_input;
	Player player;
	WINDOW* gameframe,
	      * log,
	      * menu;

	void GetKey ();
	void Stop      ();
public:
	Dungeon ();

	void Initialise ();
	void Run ();
	void Terminate ();
};

#endif
