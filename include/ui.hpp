#ifndef DUNGEON_UI
#define DUNGEON_UI

#include <clocale>
#include <ncurses.h>

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

	void DrawChar (int y, int x, const chtype ch);
};

#endif
