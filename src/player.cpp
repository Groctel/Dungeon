/** @file player.cpp
  */

#include "player.hpp"

/** @fn Player :: Player ()
  * @brief Default constructor
  *
  * Creates a player at the top right edge of the screen with a bold `@` avatar.
  */

Player :: Player ()
	:avatar ('@' | A_BOLD),
	 pos_y  (0),
	 pos_x  (0)
{ }

/** @fn Player :: Player (chtype a, int y, int x)
  * @brief Constructor with arguments
  *
  * @param a Avatar and attributes to print the player with
  * @param y Initial vertical position
  * @param x Initial horizontal position
  */

Player :: Player (chtype a, int y, int x)
	:avatar (a),
	 pos_y  (y),
	 pos_x  (x)
{ }

/** @fn chtype Player :: Avatar () const
  * @brief Avatar getter
  *
  * @return Player's avatar's character and attributes
  */

chtype Player :: Avatar () const {
	return avatar;
}

/** @fn int Player :: Y () const
  * @brief Vertical position getter
  *
  * @return Player's vertical position in the game map
  */

int Player :: Y () const {
	return pos_y;
}

/** @fn int Player :: X () const
  * @brief Horizontal position getter
  *
  * @return Player's horizontal position in the game map
  */

int Player :: X () const {
	return pos_x;
}

/** @fn void Player :: Move (WINDOW* win, Coordinate coord)
  * @brief Move the player one square to the specified coordinate
  *
  * @param win Window where the player is moved
  *
  * Checks if the player is exceeding the window limits to correct their
  * position and logs the action.
  */

void Player :: Move (WINDOW* win, Coordinate coord) {
	bool success = true;
	std::string coordinate, event;

	switch (coord) {
		case (Coordinate::e):
			coordinate = "east";

			if (++pos_x > win->_maxx - 1) {
				pos_x = win->_maxx - 1;
				success = false;
			}
		break;
		case (Coordinate::n):
			coordinate = "north";

			if (--pos_y < 1) {
				pos_y = 1;
				success = false;
			}
		break;
		case (Coordinate::s):
			coordinate = "south";

			if (++pos_y > win->_maxy - 1) {
				pos_y = win->_maxy - 1;
				success = false;
			}
		break;
		case (Coordinate::w):
			coordinate = "west";

			if (--pos_x < 1) {
				pos_x = 1;
				success = false;
			}
		break;
	}

	if (success)
		event = "Player moved one square " + coordinate;
	else
		event = "Player hit the " + coordinate + "ern wall";

	Log::Instance()->Record(event);
}
