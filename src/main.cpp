#include <ncurses.h>
#include "controller.hpp"
#include "dungeon.hpp"
#include "ui.hpp"

int main () {
	UI::Instance()->Init();
	Dungeon dungeon;
	Controller controller(dungeon);

	controller.Run();

	UI::Instance()->Stop();

	return 0;
}
