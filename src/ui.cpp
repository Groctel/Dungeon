#include "ui.hpp"

UI * UI :: instance = nullptr;

UI :: UI ()
{ }

void UI :: InitScreen () {
	setlocale(LC_CTYPE, "");
	initscr();
	noecho();
	raw();
	curs_set(0);
}

void UI :: InitWindows () {
	commandbar = newwin (1, COLS, LINES-1, 0);
	gameframe = newwin(LINES-5, COLS*0.75, 0, 0);
	gamelog = newwin(3, COLS*0.75, LINES-4, 0);
	sidemenu = newwin(LINES-1, COLS*0.25-2, 0, COLS*0.75+2);

	MakeActive(gameframe);

	mvwprintw(gamelog, 1, 1, "Move with arrows. Press 'q' to quit playing.");
}

void UI :: MakeActive (WINDOW * win) {
	activewindow = win;
	keypad(win, TRUE);
}

void UI :: RefreshWindow (WINDOW * win) {
	box(win, 0, 0);
	wrefresh(win);
}

void UI :: RefreshWindows () {
	RefreshWindow(gameframe);
	RefreshWindow(gamelog);
	RefreshWindow(sidemenu);
}

UI * UI :: Instance () {
	if (instance == nullptr)
		instance = new UI;

	return instance;
}

UI :: ~UI () {
	delete instance;
}

WINDOW * UI :: ActiveWindow () const {
	return activewindow;
}

void UI :: Init () {
	InitScreen();
	InitWindows();
	RefreshWindows();
}

void UI :: Stop () {
	delwin(commandbar);
	delwin(gameframe);
	delwin(gamelog);
	delwin(sidemenu);
	endwin();
	curs_set(1);
}

void UI :: DrawChar (int y, int x, const chtype ch) {
	mvwaddch(activewindow, y, x, ch);
	RefreshWindow(activewindow);
}

void UI :: UpdateLog () {
	if (Log::Instance()->Pending() == 1) {
		werase(gamelog);
		mvwprintw(gamelog, 1, 1, Log::Instance()->Print().c_str());
		RefreshWindow(gamelog);
	}
	else if (Log::Instance()->Pending() > 1) {
		std::stack<std::string> messages = Log::Instance()->PrintPending();
		size_t pending = messages.size();

		for (size_t i=0; i<pending; i++) {
			werase(gamelog);
			mvwprintw(gamelog, 1, 1, messages.top().c_str());
			RefreshWindow(gamelog);
			messages.pop();
		}
	}
}
