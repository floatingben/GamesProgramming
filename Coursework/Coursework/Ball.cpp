#include "Ball.h"


Ball::Ball(GLuint GLtexID, int width, int height, glm::vec2 pos)
{
	upForce = glm::vec2(0, -800);
	leftForce = glm::vec2(-10, 0);
	rightForce = glm::vec2(10, 0);
	sprite = new cSprite;
	sprite->setTexture(GLtexID);
	sprite->setSpritePos(pos);
	sprite->setTextureDimensions(width, height);
	ballWidth = width;
	ballHeight = height;
	x = pos.x,
	y = pos.y;
	ballBounds.bottom = y + ballHeight / 2;
	ballBounds.top = y - ballHeight / 2;
	ballBounds.left = x - ballWidth / 2;
	ballBounds.right = x + ballWidth / 2;
}


Ball::~Ball()
{
}


void Ball::AddUpForce(float deltaTime)
{
	pos = sprite->getSpritePos();
	sprite->setSpritePos(sprite->getSpritePos() += upForce * deltaTime);
	//sprite->setSpritePos(sprite->getSpritePos() * upForce.y * deltaTime);
}

void Ball::AddLeftForce(float deltaTime)
{
	sprite->setSpritePos(sprite->getSpritePos() * leftForce * deltaTime);
}

void Ball::AddRightForce(float deltaTime)
{
	sprite->setSpritePos(sprite->getSpritePos() * rightForce * deltaTime);
}

void Ball::AddForce(float deltaTime, glm::vec2 force)
{
	sprite->setSpritePos(sprite->getSpritePos() * force * deltaTime);
}

glm::vec2 Ball::GetUpForce()
{
	return upForce;
}

glm::vec2 Ball::GetLeftForce()
{
	return leftForce;
}

glm::vec2 Ball::GetRightForce()
{
	return rightForce;
}
RECT Ball::GetBallBounds()
{
	return ballBounds;
}

cSprite* Ball::GetSprite()
{
	return sprite;
}