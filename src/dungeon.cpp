#include "dungeon.hpp"

Dungeon :: Dungeon ()
	:running(true)
{ }

void Dungeon :: GetKey () {
	int key = wgetch(gameframe);

	switch (key) {
		case KEY_UP:
			player.MoveUp(gameframe);
		break;
		case KEY_DOWN:
			player.MoveDown(gameframe);
		break;
		case KEY_LEFT:
			player.MoveLeft(gameframe);
		break;
		case KEY_RIGHT:
			player.MoveRight(gameframe);
		break;
		case 'q':
			running = false;
		break;
	}
}

void Dungeon :: Initialise () {
/*
 *	Screen initialisation
 */
	initscr();
	noecho();
	raw();
	curs_set(0);
/*
 *	Window initialisation
 */
	gameframe = newwin(LINES-5, COLS*0.75, 0, 0);
	log = newwin(3, COLS*0.75, LINES-4, 0);
	menu = newwin(LINES-1, COLS*0.25-2, 0, COLS*0.75+2);

	box(gameframe, 0, 0);
	wrefresh(gameframe);
	box(log, 0, 0);
	mvwprintw(log, 1, 1, "Move with arrows. Press 'q' to quit playing.");
	wrefresh(log);
	box(menu, 0, 0);
	wrefresh(menu);
/*
 *	Player character initialisation
 */
	player = Player('@' | A_BOLD, gameframe->_maxy/2, gameframe->_maxx/2);
	mvwaddch(gameframe, player.Y(), player.X(), player.Avatar());
/*
 *	Capture input into the game frame
 */
	keypad(gameframe, TRUE);
}

void Dungeon :: Run () {
	while (running) {
		GetKey();
	}
}

void Dungeon :: Terminate () {
	delwin(gameframe);
	delwin(log);
	delwin(menu);
	endwin();
}
