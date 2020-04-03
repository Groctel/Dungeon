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

/** @fn void Player :: MoveUp (WINDOW* win)
  * @brief Move the player up one square
  *
  * @param win Window where the player is moved
  *
  * Checks if the player is exceeding the window limits to correct their
  * position and logs the action.
  */

void Player :: MoveUp (WINDOW* win) {
	if (--pos_y < 1)
		pos_y = 1;

	Log::Instance()->Record("Player moved one square up.");
}

/** @fn void Player :: MoveDown (WINDOW* win)
  * @brief Move the player down one square
  *
  * @param win Window where the player is moved
  *
  * Checks if the player is exceeding the window limits to correct their
  * position and logs the action.
  */

void Player :: MoveDown (WINDOW* win) {
	if (++pos_y > win->_maxy - 1)
		pos_y = win->_maxy - 1;

	Log::Instance()->Record("Player moved one square down.");
}

/** @fn void Player :: MoveLeft (WINDOW* win)
  * @brief Move the player left one square
  *
  * @param win Window where the player is moved
  *
  * Checks if the player is exceeding the window limits to correct their
  * position and logs the action.
  */

void Player :: MoveLeft (WINDOW* win) {
	if (--pos_x < 1)
		pos_x = 1;

	Log::Instance()->Record("Player moved one square left.");
}

/** @fn void Player :: MoveRight (WINDOW* win)
  * @brief Move the player right one square
  *
  * @param win Window where the player is moved
  *
  * Checks if the player is exceeding the window limits to correct their
  * position and logs the action.
  */

void Player :: MoveRight (WINDOW* win) {
	if (++pos_x > win->_maxx - 1)
		pos_x = win->_maxx - 1;

	Log::Instance()->Record("Player moved one square right.");
}
