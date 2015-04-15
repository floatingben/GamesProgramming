#ifndef Player_HEADER
#define Player_HEADER

#include "glm\glm.hpp"
#include "cInputMgr.h"
#include "GameConstants.h"
#include "cSprite.h"
#include "World.h"

class Player 
{
private:

	//the forward direction position
	glm::vec2 forwardDirection;
	//creates a variable called sprite of class CSprite
	cSprite sprite;
	//A variable called m_InputMgr that points to the class C Inputmgr
	cInputMgr* m_InputMgr;
	
	//Speed of controls
	float accelerationX;
	float DecelerationX;
	float speedX;
	float speedY;
	float maxSpeedX;
	float maxSpeedY;

	//creates the bounds for the player and sets height and width
	glm::vec2 upDirection;
	RECT playerBounds;
	float width;
	float height;
	
	//world variable that points to world class
	World* world;
	
	//score system - points of type int
	int points;

public:

	//score system - score of type int
	int score;

	Player(World *pWorld);
	//Gets the fowarddirection
	glm::vec2 GetForwardDirection();

	//Gets the sprite that points to the cSprite class
	cSprite* GetSprite();

	//Sets the player sprite
	void SetSprite(cSprite *pSprite);

	void attachInputMgr(cInputMgr* inputMgr);
	void Update(float deltaTime, World *pWorld);
	void Render();

	//a true/false bool that is used to check if something has collided with something
	bool collidedWith(RECT thisSpriteRect, RECT otherSpriteRect);
	
	//Gets the bounds of player
	RECT GetPlayerBounds();
	cInputMgr* GetInput();

	//Gets points and score and returns them
	int GetPoints(){ return points; }
	int GetScore(){ return score; }
};

#endif