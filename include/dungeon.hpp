/** @file dungeon.hpp
  */

#ifndef DUNGEON_DUNGEON
#define DUNGEON_DUNGEON

#include <ncurses.h>
#include "enum.hpp"
#include "player.hpp"
#include "ui.hpp"

/** @class Dungeon
  * @brief Dungeon model that runs the game's environment
  *
  * @var Player* player
  * Main player object
  */

class Dungeon {
private:
	Player * player;

public:
	Dungeon  ();
	~Dungeon ();

	void MovePlayer (Coordinate coord);
};

#endif
