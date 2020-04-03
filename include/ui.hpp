/** @file ui.hpp
  */

#ifndef DUNGEON_UI
#define DUNGEON_UI

#include <clocale>
#include <ncurses.h>
#include <stack>
#include "log.hpp"

/** @class UI
  * @brief Ncurses-based view that interactivaly shows the game
  *
  * @var UI* instance
  * Singleton instance pointer
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

	void Init ();
	void Stop ();

	void DrawChar  (int y, int x, const chtype ch);
	void UpdateLog ();
};

#endif
