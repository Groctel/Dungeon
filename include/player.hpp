#ifndef DUNGEON_PLAYER
#define DUNGEON_PLAYER

#include <ncurses.h>
#include "log.hpp"

class Player {
private:
	chtype avatar;
	int pos_y,
	    pos_x;
public:
/*
 *	Constructors
 */
	Player ();
	Player (chtype a, int y, int x);
/*
 *	Getters
 */
	chtype Avatar () const;
	int    Y      () const;
	int    X      () const;
/*
 *	Setters
 */
	void MoveUp    (WINDOW* win);
	void MoveDown  (WINDOW* win);
	void MoveLeft  (WINDOW* win);
	void MoveRight (WINDOW* win);
};

#endif
