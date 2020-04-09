#include "ui.hpp"

UI * UI :: instance = nullptr;

/** @fn UI :: UI ()
  * @brief Default constructor
  */

UI :: UI ()
	:min_log (0)
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
	commandbar = newwin (1,       COLS,        LINES-1, 0);
	gameframe  = newwin (LINES-7, COLS*0.75,   0,       0);
	gamelog    = newwin (5,       COLS*0.75,   LINES-6, 0);
	sidemenu   = newwin (LINES-1, COLS*0.25-2, 0,       COLS*0.75+2);

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

/** @fn const WINDOW * UI :: GameFrame () const
  * @brief Constant gameframe getter
  *
  * Compare with `UI::ActiveWindow()` to check its identity.
  *
  * @return Constant pointer to the gameframe window
  */

const WINDOW * UI :: GameFrame () const {
	return gameframe;
}

/** @fn const WINDOW * UI :: GameLog () const
  * @brief Constant gamelog getter
  *
  * Compare with `UI::ActiveWindow()` to check its identity.
  *
  * @return Constant pointer to the gamelog window
  */

const WINDOW * UI :: GameLog () const {
	return gamelog;
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
	delwin(activewindow);
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

/** @fn void UI :: CloseLog ()
  * @brief Retract the expanded log window into the docked window
  *
  * Resizes and moves the window back into the dock position and refreshes the
  * screen to get rid of artifacts. After that, it prints the last lines and
  * returns the control to the gameframe.
  */

void UI :: CloseLog () {
	wresize(gamelog, 5, COLS*0.75);
	mvwin(gamelog, LINES-6, 0);
	erase();
	refresh();
	mvwprintw(ActiveWindow(), 1, 1, Log::Instance()->Print().c_str());
	RefreshWindows();
	MakeActive(gameframe);
}

/** @fn void UI :: OpenLog ()
  * @brief Expand the docked log window over the gameframe
  *
  * Resizes and moves the window over the gameframe to show more lines than in
  * the docked position. After that, it prints the last log lines to fill the
  * window and captures the keyboard control.
  */

void UI :: OpenLog () {
	std::stack<std::string> events = Log::Instance()->Print(min_log, max_log);

	mvwin(gamelog, LINES-13, 0);
	wresize(gamelog, 12, COLS*0.75);
	MakeActive(gamelog);

	min_log = 0;
	max_log = gamelog->_maxy-1;

	ShowLog(Log::Instance()->Print(min_log, max_log));

	RefreshWindow(gamelog);
}

/** @fn void UI ::ScrollLog (Scrolling scroll)
  * @brief Scrolls the log up or down one line when the window is expanded
  *
  * @param scroll Direction to scroll the log
  */

void UI :: ScrollLog (Scrolling scroll) {
	switch (scroll) {
		case (Scrolling::d):
			max_log--;
			if (--min_log < 0) {
				min_log = 0;
				max_log++;
			}
		break;
		case (Scrolling::u):
			max_log++;
			if (++min_log > (int) Log::Instance()->Size()-1) {
				min_log = Log::Instance()->Size()-1;
				max_log--;
			}
		break;
	}

	ShowLog(Log::Instance()->Print(min_log, max_log));
}

/** @fn void UI :: ShowLog (std::stack<std::string> events)
  * @brief Display log lines to fill the gamelog window
  *
  * @param events Log lines to be displayed
  *
  * If the number of events passed to the functions is smaller than the number
  * of lines to be filled, it gets as many events as lines the window has and
  * skips the remaining top lines if the number of events is still smaller. It
  * then prints them line by line all the way to the bottom.
  */

void UI :: ShowLog (std::stack<std::string> events) {
	int line = 1;

	werase(gamelog);

	if ((int) events.size() < gamelog->_maxy) {
		events = Log::Instance()->Print(min_log, gamelog->_maxy-2);

		if ((int) events.size() < gamelog->_maxy)
			for (size_t i=0; i<gamelog->_maxy-events.size()-1; i++, line++);
	}

	for (; line<gamelog->_maxy && !events.empty(); line++) {
		mvwprintw(gamelog, line, 1, events.top().c_str());
		events.pop();
	}

	RefreshWindow(gamelog);
}
