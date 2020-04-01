#ifndef DUNGEON_PLAYER
#define DUNGEON_PLAYER

#include <ncurses.h>

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
	void Move (int ch, WINDOW* win);
};

#endif
