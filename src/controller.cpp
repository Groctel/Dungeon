#include "controller.hpp"

Controller :: Controller (Dungeon & d)
	:running (true),
	 dungeon (d)
{ }

void Controller :: Run () {
	Log::Instance()->Start();

	while (running) {
		GetKey();
		UI::Instance()->UpdateLog();
	}
}

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
