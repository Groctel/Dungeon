#include "player.hpp"

Player :: Player ()
	:avatar ('@' | A_BOLD),
	 pos_y  (0),
	 pos_x  (0)
{ }

Player :: Player (chtype a, int y, int x)
	:avatar (a),
	 pos_y  (y),
	 pos_x  (x)
{ }

chtype Player :: Avatar () const {
	return avatar;
}

int Player :: Y () const {
	return pos_y;
}

int Player :: X () const {
	return pos_x;
}

void Player :: MoveUp (WINDOW* win) {
	if (--pos_y < 1)
		pos_y = 1;

	Log::Instance()->Record("Player moved one square up.");
}

void Player :: MoveDown (WINDOW* win) {
	if (++pos_y > win->_maxy - 1)
		pos_y = win->_maxy - 1;

	Log::Instance()->Record("Player moved one square down.");
}

void Player :: MoveLeft (WINDOW* win) {
	if (--pos_x < 1)
		pos_x = 1;

	Log::Instance()->Record("Player moved one square left.");
}

void Player :: MoveRight (WINDOW* win) {
	if (++pos_x > win->_maxx - 1)
		pos_x = win->_maxx - 1;

	Log::Instance()->Record("Player moved one square right.");
}
