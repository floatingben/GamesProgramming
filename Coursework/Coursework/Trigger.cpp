#include "Trigger.h"


Trigger::Trigger(GLuint GLtexID, int width, int height, glm::vec2 pos)
{
	sprite = new cSprite;
	sprite->setTexture(GLtexID);
	sprite->setSpritePos(pos);
	sprite->setTextureDimensions(width, height);
	triggerWidth = width;
	triggerHeight = height;
	x = pos.x,
	y = pos.y;
	triggerBounds.bottom = y + triggerHeight / 2;
	triggerBounds.top = y - triggerHeight / 2;
	triggerBounds.left = x - triggerWidth / 2;
	triggerBounds.right = x + triggerWidth / 2;
}


Trigger::~Trigger()
{
}


RECT Trigger::GetTriggerBounds()
{
	return triggerBounds;
}

cSprite* Trigger::GetSprite()
{
	return sprite;
}
