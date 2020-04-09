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

/** @fn void Controller :: GetKeyGameFrame (int key)
  * @brief Get user input for the gameframe and call functions
  *
  * @param key Key pressed by the user in the gameframe
  */

void Controller :: GetKeyGameFrame (int key) {
	switch (key) {
		case KEY_UP:
			dungeon.MovePlayer(Coordinate::n);
		break;
		case KEY_DOWN:
			dungeon.MovePlayer(Coordinate::s);
		break;
		case KEY_LEFT:
			dungeon.MovePlayer(Coordinate::w);
		break;
		case KEY_RIGHT:
			dungeon.MovePlayer(Coordinate::e);
		break;
		case 'l':
			UI::Instance()->OpenLog();
		break;
		case 'q':
			running = false;
		break;
	}
}

/** @fn void Controller :: GetKeyGameLog (int key)
  * @brief Get user input for the gamelog and call functions
  *
  * @param key Key pressed by the user in the gamelog
  */

void Controller ::GetKeyGameLog (int key) {
	switch (key) {
		case KEY_UP:
			UI::Instance()->ScrollLog(Scrolling::u);
		break;
		case KEY_DOWN:
			UI::Instance()->ScrollLog(Scrolling::d);
		break;
		case 'q':
			UI::Instance()->CloseLog();
		break;
	}
}

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

		if (UI::Instance()->ActiveWindow() != UI::Instance()->GameLog())
			UI::Instance()->ShowLog(Log::Instance()->PrintPending());
	}
}

/** @fn void Controller :: GetKey (int key)
  * @brief Capture user input and send to the appropriate window getter
  *
  * @param key Key pressed by the user in the active window
  *
  * Checks the active window's identity and send the key to the appropriate
  * private getter, allowing for multiple definitions of individual keys managed
  * by each window's context.
  */

void Controller :: GetKey (int key) {
	if (UI::Instance()->ActiveWindow() == UI::Instance()->GameFrame())
		GetKeyGameFrame(key);
	else if (UI::Instance()->ActiveWindow() == UI::Instance()->GameLog())
		GetKeyGameLog(key);
}
