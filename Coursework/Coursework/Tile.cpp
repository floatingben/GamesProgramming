#include "Tile.h"


Tile::Tile(GLuint GLtexID, int width, int height, glm::vec2 pos)
{
	tileSprite = new cSprite;
	tileSprite->setTexture(GLtexID);
	tileSprite->setSpritePos(pos);
	tileSprite->setTextureDimensions(width, height);
	tileWidth = width;
	tileHeight = height;
	x = pos.x,
	y = pos.y;
	tileBounds.bottom = y + tileHeight / 2;
	tileBounds.top = y - tileHeight / 2;
	tileBounds.left = x - tileWidth / 2;
	tileBounds.right = x + tileWidth / 2;	
}


Tile::~Tile()
{
}


cSprite* Tile::GetSprite()
{
	return tileSprite;
}

RECT Tile::GetTileBounds()
{
	return tileBounds;
}