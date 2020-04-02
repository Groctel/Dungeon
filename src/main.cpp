#include <ncurses.h>
#include "dungeon.hpp"
#include "log.hpp"

Log * Log::instance = nullptr;

int main () {
	Dungeon dungeon;

	dungeon.Initialise();
	dungeon.Run();
	dungeon.Terminate();

	return 0;
}
