/** @file dungeon.cpp
  */

#include "dungeon.hpp"

/** @fn Dungeon :: Dungeon ()
  * @brief Default constructor
  *
  * Initialises the player object in the middle of the game screen (guaranteed
  * to be `UI::gameframe` for now) and calls the UI to draw it.
  */

Dungeon :: Dungeon () {
	player = new Player('@' | A_BOLD,
	                    UI::Instance()->ActiveWindow()->_maxy/2,
	                    UI::Instance()->ActiveWindow()->_maxx/2);

	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

/** @fn Dungeon :: ~Dungeon ()
  * @brief Default destructor
  *
  * Frees the player object's memory.
  */

Dungeon :: ~Dungeon () {
	delete player;
}

/** @fn void Dungeon :: MovePlayer (Coordinate coord)
  * @brief Move the player one square to the specified coordinate
  *
  * Prints a blank character where the player is currently standing, calls the
  * player to calculate its new position and prints the player in the new
  * position.
  */

void Dungeon :: MovePlayer (Coordinate coord) {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->Move(UI::Instance()->ActiveWindow(), coord);
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}
