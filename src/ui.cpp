#include "ui.hpp"

UI * UI :: instance = nullptr;

/** @fn UI :: UI ()
  * @brief Default constructor
  */

UI :: UI ()
{ }

/** @fn void UI :: InitScreen ()
  * @brief Ncurses initializator
  *
  * Starts an `ncurses` environment with wide characters support and game-ready
  * parameters.
  */

void UI :: InitScreen () {
	setlocale(LC_CTYPE, "");
	initscr();
	noecho();
	raw();
	curs_set(0);
}

/** @fn void UI :: InitWindows ()
  * @brief Game windows initialiser
  *
  * Initialises the four game windows and sets the `press 'q' to quit' message
  * to be displayed at the `gamelog` window. Also sets the `gameframe` as the
  * active window.
  */

void UI :: InitWindows () {
	commandbar = newwin (1, COLS, LINES-1, 0);
	gameframe = newwin(LINES-5, COLS*0.75, 0, 0);
	gamelog = newwin(3, COLS*0.75, LINES-4, 0);
	sidemenu = newwin(LINES-1, COLS*0.25-2, 0, COLS*0.75+2);

	MakeActive(gameframe);

	mvwprintw(gamelog, 1, 1, "Move with arrows. Press 'q' to quit playing.");
}

/** @fn void UI :: MakeActive (WINDOW * win)
  * @brief Main window setter.
  *
  * @param win Window to make active
  *
  * Makes `win` the active window and captures the keypad into it.
  */

void UI :: MakeActive (WINDOW * win) {
	activewindow = win;
	keypad(win, TRUE);
}

/** @fn void UI :: RefreshWindow (WINDOW * win)
  * @brief Window refresher
  *
  * @param win Window to be refreshed
  *
  * Draws a box around the window and refreshes it.
  */

void UI :: RefreshWindow (WINDOW * win) {
	box(win, 0, 0);
	wrefresh(win);
}

/** @fn void UI :: RefreshWindows ()
  * @brief General windows refresher
  *
  * Calls `UI::RefreshWindow` for each window to refresh them all.
  */

void UI :: RefreshWindows () {
	RefreshWindow(gameframe);
	RefreshWindow(gamelog);
	RefreshWindow(sidemenu);
}

/** @fn UI * UI :: Instance ()
  * @brief UI's singleton instance getter
  *
  * If the instance doesn't exist (`== nullptr`), it creates a UI instance.
  *
  * @return Unique instance pointer
  */

UI * UI :: Instance () {
	if (instance == nullptr)
		instance = new UI;

	return instance;
}

/** @fn UI :: ~UI ()
  * @brief Default destructor
  *
  * Free's the UI's instance memory.
  */

UI :: ~UI () {
	delete instance;
}

/** @fn WINDOW * UI :: ActiveWindow ()
  * @brief Active window getter
  *
  * @return Current active window's pointer
  */

WINDOW * UI :: ActiveWindow () const {
	return activewindow;
}

/** @fn void UI :: Init ()
  * @brief General UI initialiser
  *
  * Calls `UI::InitScreen`, `UI::InitWindows` and `UI::RefreshWindows` to
  * initialise the `ncurses` environment.
  */

void UI :: Init () {
	InitScreen();
	InitWindows();
	RefreshWindows();
}

/** @fn void UI :: Stop ()
  * @brief General UI stopper
  *
  * Deletes all windows, closes the `ncurses` environment and set the cursor
  * back to normal.
  */

void UI :: Stop () {
	delwin(commandbar);
	delwin(gameframe);
	delwin(gamelog);
	delwin(sidemenu);
	endwin();
	curs_set(1);
}

/** @fn void UI :: DrawChar (int y, int x, const chtype ch)
  * @brief Single character drawer
  *
  * @param y Vertical position to print the character in
  * @param x Horizontal position to print the character in
  * @param ch Character and attributes to print
  *
  * Prints a character in the active window and refreshes it.
  */

void UI :: DrawChar (int y, int x, const chtype ch) {
	mvwaddch(activewindow, y, x, ch);
	RefreshWindow(activewindow);
}

/** @fn void UI :: UpdateLog ()
  * @brief Log window updater
  *
  * Gets the log's pending events and prints them one by one in the log
  * window.
  */

void UI :: UpdateLog () {
	std::stack<std::string> events = Log::Instance()->PrintPending();
	size_t pending = events.size();

	for (size_t i=0; i<pending; i++) {
		werase(gamelog);
		mvwprintw(gamelog, 1, 1, events.top().c_str());
		RefreshWindow(gamelog);
		events.pop();
	}
}
