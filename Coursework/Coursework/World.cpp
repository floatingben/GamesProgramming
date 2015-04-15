#include "World.h"

World::World()
{
	//renders each apple in the world
	renderApple1 = true;
	renderApple2 = true;
	renderApple3 = true;
	renderApple4 = true;
	renderApple5 = true;
	renderApple6 = true;
	renderApple7 = true;
	renderApple8 = true;
	renderApple9 = true;
	renderApple10 = true;
}

World::~World()
{
}

void World::SetBush(GLuint GLtexID, int width, int height)
{
		
	//bushes and their position
	for (int i = 0; i < 120; i++)
	{
		glm::vec2 pos1;

		if (i < 12)
		{
			pos1 = glm::vec2(0, i * 64); //long column1
		}

		else if (i > 11 && i < 25)
		{
			pos1 = glm::vec2(64, i * 64 - 795); //long column2
		}

		else if (i>24 && i < 28)
		{
			pos1 = glm::vec2(200, i * 64 - 1030); //lowerfirst3
		}

		else if (i>28 && i < 32)
		{
			pos1 = glm::vec2(265, i * 64 - 1284); //lowersecond3
		}

		else if (i>32 && i < 36)
		{
			pos1 = glm::vec2(330, i * 64 - 1542); //lowerthird3
		}

		else if (i>36 && i < 40)
		{
			pos1 = glm::vec2(200, i * 64 - 2040); //upperfirst3
		}

		else if (i>40 && i < 44)
		{
			pos1 = glm::vec2(265, i * 64 - 2300); //uppersecond3
		}

		else if (i>44 && i < 48)
		{
			pos1 = glm::vec2(330, i * 64 - 2555); //upperthird3
		}

		else if (i>48 && i < 51)
		{
			pos1 = glm::vec2(400, i * 64 - 2565); //lowerfist2bushes
		}

		else if (i>51 && i < 54)
		{
			pos1 = glm::vec2(470, i * 64 - 2758); //lowersecond2bushes
		}

		else if (i>54 && i < 57)
		{
			pos1 = glm::vec2(540, i * 64 - 2950);//lowerthird2bushes
		}

		else if (i>57 && i < 59)
		{
			pos1 = glm::vec2(400, i * 64 - 3325); //middlefirst
		}

		else if (i>59 && i < 61)
		{
			pos1 = glm::vec2(465, i * 64 - 3460);//middlesecond
		}

		else if (i>61 && i < 65)
		{
			pos1 = glm::vec2(533, i * 64 - 3653); //middlefirstright
		}

		else if (i>65 && i < 69)
		{
			pos1 = glm::vec2(600, i * 64 - 3915); //middlesecondright
		}

		else if (i>69 && i<73)
		{
			pos1 = glm::vec2(668, i * 64 - 4170); //middlethirdright
		}

		else if (i>73 && i < 78)
		{
			pos1 = glm::vec2(395, i * 64 - 4715);
		}

		else if (i>78 && i<83)
		{
			pos1 = glm::vec2(460, i * 64 - 5038);
		}

		else if (i>83 && i < 87)
		{
			pos1 = glm::vec2(600, i * 64 - 5350);
		}

		else if (i>87 && i < 91)
		{
			pos1 = glm::vec2(670, i * 64 - 5610);
		}

		else if (i>91 && i < 95)
		{
			pos1 = glm::vec2(743, i * 64 - 5870);
		}

		else if (i>95 && i < 99)
		{
			pos1 = glm::vec2(815, i * 64 - 6131);
		}

		else if (i>99 && i < 113)
		{
			pos1 = glm::vec2(1000, i * 64 - 6480);
		}

		else if (i>113 && i < 116)
		{
			pos1 = glm::vec2(743, i * 64 - 6700);
		}

		else if (i>116 && i < 119)
		{
			pos1 = glm::vec2(810, i * 64 - 6895);
		}
		Tile *bush = new Tile (GLtexID, width, height, pos1);
		bushTiles.push_back(bush);

	}

}

//Sets apples with new and assigns value positions
void World::SetApple(GLuint GLtexA, int width, int height)
{
		apple1 = new Tile(GLtexA, width, height, glm::vec2(100, 100));
		apple2 = new Tile(GLtexA, width, height, glm::vec2(200, 100));
		apple3 = new Tile(GLtexA, width, height, glm::vec2(530, 100));
		apple4 = new Tile(GLtexA, width, height, glm::vec2(900, 100));
		apple5 = new Tile(GLtexA, width, height, glm::vec2(120, 400));
		apple6 = new Tile(GLtexA, width, height, glm::vec2(385, 335));
		apple7 = new Tile(GLtexA, width, height, glm::vec2(925, 650));
		apple8 = new Tile(GLtexA, width, height, glm::vec2(900, 400));
		apple9 = new Tile(GLtexA, width, height, glm::vec2(385, 690));
		apple10 = new Tile(GLtexA, width, height, glm::vec2(395, 450));
}


//renders the bush tiles and each apple
void World::render()
{
	for (int i = 0; i < 120; i++)
		bushTiles[i]->GetSprite()->render();

	if (renderApple1)
	{
		apple1->GetSprite()->render();
	}
	if (renderApple2)
	{
		apple2->GetSprite()->render();
	}
	if (renderApple3)
	{
		apple3->GetSprite()->render();
	}
	if (renderApple4)
	{
		apple4->GetSprite()->render();
	}
	if (renderApple5)
	{
		apple5->GetSprite()->render();
	}
	if (renderApple6)
	{
		apple6->GetSprite()->render();
	}
	if (renderApple7)
	{
		apple7->GetSprite()->render();
	}
	if (renderApple7)
	{
		apple7->GetSprite()->render();
	}
	if (renderApple8)
	{
		apple8->GetSprite()->render();
	}
	if (renderApple9)
	{
		apple9->GetSprite()->render();
	}
	if (renderApple10)
	{
		apple10->GetSprite()->render();
	}
	

}
vector<Tile*> &World::GetBushTiles()
{
	return bushTiles;
}

