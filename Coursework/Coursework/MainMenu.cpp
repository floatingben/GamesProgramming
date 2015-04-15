#include "MainMenu.h"


MainMenu::MainMenu(Player *pPlayer)
{
	state = helpMenu;
	player = pPlayer;
}


MainMenu::~MainMenu()
{
}

void MainMenu::Update()
{
	if (player->GetInput()->isKeyDown(VK_SPACE))
	{
		state = Game;
	}
		
}