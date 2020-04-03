#include "dungeon.hpp"

Dungeon :: Dungeon () {
	player = new Player('@' | A_BOLD,
	                    UI::Instance()->ActiveWindow()->_maxy/2,
	                    UI::Instance()->ActiveWindow()->_maxx/2);

	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

Dungeon :: ~Dungeon () {
	delete player;
}

void Dungeon :: MovePlayerUp () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveUp(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

void Dungeon :: MovePlayerDown () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveDown(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

void Dungeon :: MovePlayerLeft () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveLeft(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}

void Dungeon :: MovePlayerRight () {
	UI::Instance()->DrawChar(player->Y(), player->X(), ' ');
	player->MoveRight(UI::Instance()->ActiveWindow());
	UI::Instance()->DrawChar(player->Y(), player->X(), player->Avatar());
}
