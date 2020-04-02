#include <ncurses.h>
#include "player.hpp"

int main () {
/*
 *	Variables declaration
 */
	int ch;
	Player player;
	WINDOW* gameframe,
	      * log,
	      * menu;
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
/*
 *	Move the player until the game quits
 */
	while ((ch = wgetch(gameframe)) != 'q') {
	/*
	 *	Empty the player's current square
	 */
		mvwaddch(gameframe, player.Y(), player.X(), ' ');
	/*
	 *	Move the player depending on input
	 */
		player.Move(ch, gameframe);
	/*
	 *	Print the interface and the player's avatar over it and refresh
	 */
		mvwaddch(gameframe, player.Y(), player.X(), player.Avatar());
	};
/*
 *	Close the ncurses environment and return
 */
	endwin();
	return 0;
}
