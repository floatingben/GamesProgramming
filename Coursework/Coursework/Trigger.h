#pragma once
#include "GameConstants.h"
#include "cSprite.h"
class Trigger
{
private:
	RECT triggerBounds;
	cSprite *sprite;
	float triggerWidth;
	float triggerHeight;
	float x;
	float y;
	glm::vec2 pos;
public:
	Trigger(GLuint GLtexID, int width, int height, glm::vec2 pos);
	~Trigger();
	RECT GetTriggerBounds();
	cSprite* GetSprite();
};

