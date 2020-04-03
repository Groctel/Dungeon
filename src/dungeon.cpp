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

/** @fn void Dungeon :: MovePlayerUp ()
  * @brief Move the player up one square
  *
  * Prints a blank character where the player is currently standing, calls the
  * player to calculate its new position and prints the player in the new
  * position.
  */

void Dungeon :: MovePlayerUp () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveUp(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

/** @fn void Dungeon :: MovePlayerDown ()
  * @brief Move the player down one square
  *
  * Prints a blank character where the player is currently standing, calls the
  * player to calculate its new position and prints the player in the new
  * position.
  */

void Dungeon :: MovePlayerDown () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveDown(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

/** @fn void Dungeon :: MovePlayerLeft ()
  * @brief Move the player left one square
  *
  * Prints a blank character where the player is currently standing, calls the
  * player to calculate its new position and prints the player in the new
  * position.
  */

void Dungeon :: MovePlayerLeft () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveLeft(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

/** @fn void Dungeon :: MovePlayerRight ()
  * @brief Move the player right one square
  *
  * Prints a blank character where the player is currently standing, calls the
  * player to calculate its new position and prints the player in the new
  * position.
  */

void Dungeon :: MovePlayerRight () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveRight(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}
