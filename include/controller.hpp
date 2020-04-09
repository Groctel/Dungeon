/** @file controller.hpp
  */

#ifndef DUNGEON_CONTROLLER
#define DUNGEON_CONTROLLER

#include <ncurses.h>
#include "dungeon.hpp"
#include "enum.hpp"
#include "player.hpp"
#include "ui.hpp"

/** @class Controller
  * @brief Game controller the user interacts with
  *
  * @var bool running
  * Game running status. Set to `false` to stop the game.
  *
  * @var Dungeon & dungeon
  * Dungeon model game action commands are sent to.
  */

class Controller {
private:
	bool running;
	Dungeon & dungeon;

	void GetKeyGameFrame (int key);
	void GetKeyGameLog   (int key);
public:
	Controller (Dungeon & d);

	void Run ();

	void GetKey (int key = wgetch(UI::Instance()->ActiveWindow()));
};


#endif
