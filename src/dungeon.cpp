#include <ncurses.h>

int main () {
	int y, x, ch;
	char player = '@';

	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);

	y = LINES / 2;
	x = COLS / 2;

	mvaddch(y, x, player | A_BOLD);
	refresh();

	while ((ch = getch()) != KEY_F(1)) {
		mvaddch(y, x, ' ');

		switch (ch) {
			case KEY_UP:
				mvaddch(--y, x, player | A_BOLD);
			break;
			case KEY_DOWN:
				mvaddch(++y, x, player | A_BOLD);
			break;
			case KEY_LEFT:
				mvaddch(y, --x, player | A_BOLD);
			break;
			case KEY_RIGHT:
				mvaddch(y, ++x, player | A_BOLD);
			break;
			default:
				mvaddch(y, x, player | A_BOLD);
		}

		refresh();
	};

	endwin();
}
