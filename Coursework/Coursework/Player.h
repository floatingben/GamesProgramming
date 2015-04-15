#ifndef Player_HEADER
#define Player_HEADER

#include "glm\glm.hpp"
#include "cInputMgr.h"
#include "GameConstants.h"
#include "cSprite.h"
#include "Physics.h"
#include "D2d1.h"
#include "World.h"
#include "Trigger.h"
#include "Ball.h"

class Player 
{
private:

	glm::vec2 forwardDirection;
	cSprite sprite;
	cInputMgr* m_InputMgr;
	float accelerationX;
	float DecelerationX;
	float speedX;
	float speedY;
	float maxSpeedX;
	float maxSpeedY;
	//float jumpSpeedY;
	//float gravity;
	//bool jumping;
	bool jumpkeyDown;
	float m_lastTime;
	glm::vec2 upDirection;
	RECT playerBounds;
	float width;
	float height;
	static const int iterations = 3;
	World* world;
	int points;

public:

	int score;
	Player(World *pWorld);
	glm::vec2 GetForwardDirection();
	cSprite* GetSprite();
	void SetSprite(cSprite *pSprite);
	void attachInputMgr(cInputMgr* inputMgr);
	void Update(float deltaTime, World *pWorld);
	void Render();
	//void Collide(glm::vec2 playerPos);
	bool collidedWith(RECT thisSpriteRect, RECT otherSpriteRect);
	RECT GetPlayerBounds();
	cInputMgr* GetInput();
	int GetPoints(){ return points; }
	int GetScore(){ return score; }
};

#endif