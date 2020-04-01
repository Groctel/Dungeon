#include <ncurses.h>
#include "player.hpp"

int main () {
/*
 *	Variables declaration
 */
	int ch, height, width, starty, startx;
	Player player;
	WINDOW* gameframe;
/*
 *	Screen initialisation
 */
	initscr();
	noecho();
	raw();
	curs_set(0);
/*
 *	Interface initialisation
 */
	printw ("Y: %d/%d\nX: %d/%d\nPress [F1] to quit",
	        player.Y(), LINES, player.X(), COLS);
	refresh();
/*
 *	Window initialisation
 */
	height = LINES / 4;
	width  = COLS / 4;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	gameframe = newwin(height, width, starty, startx);
	box(gameframe, 0, 0);
	wrefresh(gameframe);
/*
 *	Player character initialisation
 */
	player = Player('@' | A_BOLD, height/2, width/2);
	mvwaddch(gameframe, player.Y(), player.X(), player.Avatar());
/*
 *	Capture input into the game frame
 */
	keypad(gameframe, TRUE);
/*
 *	Move the player until the game quits
 */
	while ((ch = wgetch(gameframe)) != KEY_F(1)) {
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
		mvprintw (0, 0, "Y: %d/%d\nX: %d/%d\nPress [F1] to quit",
		                player.Y(), LINES, player.X(), COLS);
		mvwaddch(gameframe, player.Y(), player.X(), player.Avatar());
		refresh();
	};
/*
 *	Close the ncurses environment and return
 */
	endwin();
	return 0;
}
