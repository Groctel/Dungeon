/** @file player.hpp
  */

#ifndef DUNGEON_PLAYER
#define DUNGEON_PLAYER

#include <ncurses.h>
#include "log.hpp"

/** @class Player
  * @brief Player object
  *
  * @var chtype avatar
  * Character and attributes the player is rendered with
  *
  * @var int pos_y
  * Vertical position of the player in the game map
  *
  * @var int pos_x
  * Horizontal position of the player in the game map
  */

class Player {
private:
	chtype avatar;
	int pos_y,
	    pos_x;

public:
	Player ();
	Player (chtype a, int y, int x);

	chtype Avatar () const;
	int    Y      () const;
	int    X      () const;

	void MoveUp    (WINDOW* win);
	void MoveDown  (WINDOW* win);
	void MoveLeft  (WINDOW* win);
	void MoveRight (WINDOW* win);
};

#endif
