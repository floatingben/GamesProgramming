#pragma once
#include "cSprite.h"
class Ball
{
private:
	cSprite *sprite;
	glm::vec2 upForce;
	glm::vec2 leftForce;
	glm::vec2 rightForce;
	RECT ballBounds;
	float ballWidth;
	float ballHeight;
	float x;
	float y;
	glm::vec2 pos;
public:
	Ball(GLuint GLtexID, int width, int height, glm::vec2 pos);
	~Ball();
	cSprite* GetSprite();
	float width;
	float height;
	void AddUpForce(float deltaTime);
	void AddLeftForce(float deltaTime);
	void AddRightForce(float deltaTime);
	void AddForce(float deltaTime, glm::vec2 force);
	glm::vec2 GetUpForce();
	glm::vec2 GetLeftForce();
	glm::vec2 GetRightForce();
	RECT GetBallBounds();
};

