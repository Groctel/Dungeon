/** @file ui.hpp
  */

#ifndef DUNGEON_UI
#define DUNGEON_UI

#include <clocale>
#include <ncurses.h>
#include <stack>
#include <string>
#include "enum.hpp"
#include "log.hpp"

/** @class UI
  * @brief Ncurses-based view that interactivaly shows the game
  *
  * @var UI* instance
  * Singleton instance pointer
  *
  * @var int min_log
  * Most recent event to be printed at the log window
  *
  * @var int max_log
  * Oldest event to be printed at the log window
  *
  * @var WINDOW* activewindow
  * Window the player is currently controlling
  *
  * @var WINDOW* commandbar
  * Command bar at the bottom of the interface
  *
  * @var WINDOW* gameframe
  * Frame inside of which the dungeon is rendered
  *
  * @var WINDOW* gamelog
  * Small bar below the `gameframe` displaying the log
  *
  * @var WINDOW* sidemenu
  * Multipurpose menu at the right side of the screen
  */

class UI {
private:
	static UI * instance;

	int min_log,
	    max_log;

	WINDOW * activewindow,
	       * commandbar,
	       * gameframe,
	       * gamelog,
	       * sidemenu;

	UI ();
	UI (const UI & other) = delete;

	void InitScreen     ();
	void InitWindows    ();
	void MakeActive     (WINDOW * win);
	void RefreshWindow  (WINDOW * win);
	void RefreshWindows ();

public:
	static UI * Instance ();
	~UI ();

	WINDOW * ActiveWindow () const;
	const WINDOW * GameFrame () const;
	const WINDOW * GameLog () const;

	void Init ();
	void Stop ();

	void DrawChar  (int y, int x, const chtype ch);

	void CloseLog  ();
	void OpenLog   ();
	void ScrollLog (Scrolling scroll);
	void ShowLog   (std::stack<std::string> events
	                = Log::Instance()->PrintPending());
};

#endif
