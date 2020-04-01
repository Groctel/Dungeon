#include <ncurses.h>

int main () {
/*
 *	Variables declaration
 */
	int y, x, ch, height, width, starty, startx;
	char player = '@';
	WINDOW* gameframe;
/*
 *	Screen initialisation
 */
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
/*
 *	Player initial position
 */
	y = LINES / 2;
	x = COLS / 2;
/*
 *	Interface initialisation
 */
	printw("Y: %d/%d\nX: %d/%d\nPress [F1] to quit", y, LINES, x, COLS);
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
 *	Character initialisation
 */
	mvaddch(y, x, player | A_BOLD);
/*
 *	Move the player until the game quits
 */
	while ((ch = getch()) != KEY_F(1)) {
	/*
	 *	Empty the player's current square
	 */
		mvaddch(y, x, ' ');
	/*
	 *	Move the player depending on input
	 */
		switch (ch) {
		//	Move up (negative y) when the up arrow key is pressed
			case KEY_UP:
				if (--y < starty+1)
					y = starty+1;
			break;
		//	Move down (positive y) when the down arrow key is pressed
			case KEY_DOWN:
				if (++y > starty+height-2)
					y = starty+height-2;
			break;
		//	Move left (negative x) when the left arrow key is pressed
			case KEY_LEFT:
				if (--x < startx+1)
					x = startx+1;
			break;
		//	Move right (positive x) when the right arrow key is pressed
			case KEY_RIGHT:
				if (++x > startx+width-2)
					x = startx+width-2;
			break;
		}
	/*
	 *	Print the interface and the player's avatar over it and refresh
	 */
		mvprintw(0, 0, "Y: %d/%d\nX: %d/%d\nPress [F1] to quit",
		                y, LINES, x, COLS);
		mvaddch(y, x, player | A_BOLD);
	};
/*
 *	Close the ncurses environment
 */
	endwin();
}
