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

	printw("Y: %d/%d\nX: %d/%d\nPress [F1] to quit", y, LINES, x, COLS);

	mvaddch(y, x, player | A_BOLD);
	refresh();

	while ((ch = getch()) != KEY_F(1)) {
		mvprintw(0, 0, "Y: %d/%d\nX: %d/%d\nPress [F1] to quit",
		                y, LINES, x, COLS);
		mvaddch(y, x, ' ');

		switch (ch) {
			case KEY_UP:
				if (--y < 0)
					y = 0;

				mvaddch(y, x, player | A_BOLD);
			break;

			case KEY_DOWN:
				if (++y > LINES-1)
					y = LINES-1;

				mvaddch(y, x, player | A_BOLD);
			break;

			case KEY_LEFT:
				if (--x < 0)
					x = 0;

				mvaddch(y, x, player | A_BOLD);
			break;

			case KEY_RIGHT:
				if (++x > COLS-1)
					x = COLS-1;

				mvaddch(y, x, player | A_BOLD);
			break;
			default:
				mvaddch(y, x, player | A_BOLD);
		}

		refresh();
	};

	endwin();
}
