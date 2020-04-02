#include <ncurses.h>
#include "dungeon.hpp"

int main () {
	Dungeon dungeon;

	dungeon.Initialise();
	dungeon.Run();
	dungeon.Terminate();

	return 0;
}
