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

void Player :: Move (int ch, WINDOW* win) {
	switch (ch) {
	//	Move up (negative y) when the up arrow key is pressed
		case KEY_UP:
			if (--pos_y < 1)
				pos_y = 1;
		break;
	//	Move down (positive y) when the down arrow key is pressed
		case KEY_DOWN:
			if (++pos_y > win->_maxy - 1)
				pos_y = win->_maxy - 1;
		break;
	//	Move left (negative x) when the left arrow key is pressed
		case KEY_LEFT:
			if (--pos_x < 1)
				pos_x = 1;
		break;
	//	Move right (positive x) when the right arrow key is pressed
		case KEY_RIGHT:
			if (++pos_x > win->_maxx - 1)
				pos_x = win->_maxx - 1;
		break;
	}
}
