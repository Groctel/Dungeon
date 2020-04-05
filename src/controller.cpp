/** @file controller.cpp
  */

#include "controller.hpp"

/** @fn Controller :: Controller (Dungeon & d)
  * @brief Constructor with arguments
  *
  * @param d Initialised dungeon model reference
  *
  * As of now, starting the controller sets the game running status to `true`.
  * If the game gets a title screen or preliminary menus of any sort, this will
  * have to be changed to `false` and be set to true in a different methos.
  * Maybe in `Controller::Run`?
  */

Controller :: Controller (Dungeon & d)
	:running (true),
	 dungeon (d)
{ }

/** @fn void Controller :: Run ()
  * @brief Main game loop
  *
  * Initialises the log to set the effective game start timestamp and runs the
  * game by capturing the user's input and updating the log window.
  */

void Controller :: Run () {
	Log::Instance()->Reset();

	while (running) {
		GetKey();
		UI::Instance()->UpdateLog();
	}
}

/** @fn void Controller :: GetKey (int key)
  * @brief Capture user input and call functions
  *
  * @param key Key pressed by the user in the active window
  *
  * As of now, `UI::gameframe` stays as the active window for the duration of
  * the game. When the interface gets more complex different getters will be set
  * for different windows to simplify the code and reduce the sequential search
  * time.
  */

void Controller :: GetKey (int key) {
	switch (key) {
		case KEY_UP:
			dungeon.MovePlayerUp();
		break;
		case KEY_DOWN:
			dungeon.MovePlayerDown();
		break;
		case KEY_LEFT:
			dungeon.MovePlayerLeft();
		break;
		case KEY_RIGHT:
			dungeon.MovePlayerRight();
		break;
		case 'q':
			running = false;
		break;
	}
}
