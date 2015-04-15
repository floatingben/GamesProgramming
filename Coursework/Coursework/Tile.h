#pragma once

#include "cSprite.h"
class Tile : public cSprite
{
private:
	cSprite *tileSprite;
	RECT tileBounds;
	float x;
	float y;
	glm::vec2 pos;
	float tileWidth;
	float tileHeight;

public:
	Tile(GLuint GLtexID, int width, int height, glm::vec2 pos);
	~Tile();
	cSprite* GetSprite();
	RECT GetTileBounds();
	glm::vec2 GetPos() { return glm::vec2(x, y); }
};

