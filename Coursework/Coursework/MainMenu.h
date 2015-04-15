#pragma once
#include "cSprite.h"
#include "World.h"
#include "Player.h"
class MainMenu
{
private:
	cSprite * sprite;
	World *world;
	Player * player;
	gameMode state;

public:
	MainMenu( Player* player);
	~MainMenu();
	cSprite* GetSprite(){ return sprite; }
	void Update();
	gameMode GetState(){ return state; }
};

