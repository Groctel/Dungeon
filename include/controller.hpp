#ifndef DUNGEON_CONTROLLER
#define DUNGEON_CONTROLLER

#include <ncurses.h>
#include "dungeon.hpp"
#include "player.hpp"
#include "ui.hpp"

class Controller {
private:
	bool running;
	Dungeon & dungeon;

public:
	Controller (Dungeon & d);

	void Run ();

	void GetKey (int key = wgetch(UI::Instance()->ActiveWindow()));
};


#endif
