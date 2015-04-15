//Header files player and cSprite
#include "Player.h" 
#include "cSprite.h"


Player::Player(World *pWorld)
{
	score = 0;
	world = pWorld;
	sprite.setSpritePos(glm::vec2(80, 0));
	float velocity = 50;
	accelerationX = 10 * velocity;
	DecelerationX = 10 * velocity;
	maxSpeedX = 5 * velocity;
	maxSpeedY = 10 * velocity;
	speedX = 0;
	speedY = 0;
	m_lastTime = 0;
	forwardDirection = glm::vec2(1, 0);
	upDirection = glm::vec2(0, -1);
}

glm::vec2 Player::GetForwardDirection()
{
	return forwardDirection;
}

cSprite* Player::GetSprite()
{
	return &sprite;
}

void Player::SetSprite(cSprite *pSprite)
{
	sprite = *pSprite;
	width = sprite.GetTextureWidth();
	height = sprite.GetTextureHeight();
}

void Player::attachInputMgr(cInputMgr* inputMgr)
{
	m_InputMgr = inputMgr;
}

void Player::Update(float deltaTime, World *pWorld)
{
	glm::vec2 playerPos = sprite.getSpritePos();
	playerPos.x += deltaTime * speedX;
	playerPos.y += deltaTime * speedY;
	playerPos.x = (int)playerPos.x;
	playerPos.y = (int)playerPos.y;
	sprite.setSpritePos(playerPos);
	playerBounds.bottom = playerPos.y + height / 2;
	playerBounds.top = playerPos.y - height / 2;
	playerBounds.left = playerPos.x - width / 2;
	playerBounds.right = playerPos.x + width / 2;

	if (m_InputMgr->isKeyDown(VK_RIGHT))
	{
		speedX += 30 * deltaTime;
	}
	else if (m_InputMgr->isKeyDown(VK_LEFT))
	{
		speedX -= 30 * deltaTime;
	}

	else if (m_InputMgr->isKeyDown(VK_UP))
	{
		speedY -= 30 * deltaTime;
	}
	else if (m_InputMgr->isKeyDown(VK_DOWN))
	{
		speedY += 30 * deltaTime;
	}
	else
	{
		speedX = 0;
		speedY = 0;
	}

	if (speedX > maxSpeedX)
	{
		speedX = maxSpeedX;
	}
	if (speedX < -maxSpeedX)
	{
		speedX = -maxSpeedX;
	}
	if (speedY < -maxSpeedY)
	{
		speedY = -maxSpeedY;
	}


	if (collidedWith(playerBounds, world->GetApple1()->GetTileBounds())) {
		world->SetrenderApple1(false);
		delete world->GetApple1(); 
		score++;
		}
	if (collidedWith(playerBounds, world->GetApple2()->GetTileBounds())) {
		world->SetrenderApple2(false);
		delete world->GetApple2();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple3()->GetTileBounds())) {
		world->SetrenderApple3(false);
		delete world->GetApple3();
		score++;

	}
	if (collidedWith(playerBounds, world->GetApple4()->GetTileBounds())) {
		world->SetrenderApple4(false);
		delete world->GetApple4();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple5()->GetTileBounds())) {
		world->SetrenderApple5(false);
		delete world->GetApple5();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple6()->GetTileBounds())) {
		world->SetrenderApple6(false);
		delete world->GetApple6();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple7()->GetTileBounds())) {
		world->SetrenderApple7(false);
		delete world->GetApple7();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple8()->GetTileBounds())) {
		world->SetrenderApple8(false);
		delete world->GetApple8();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple9()->GetTileBounds())) {
		world->SetrenderApple9(false);
		delete world->GetApple9();
		score++;
	}
	if (collidedWith(playerBounds, world->GetApple10()->GetTileBounds())) {
		world->SetrenderApple10(false);
		delete world->GetApple10();
		score++;
	}

}

void Player::Render()
{
	sprite.render();
}
bool Player::collidedWith(RECT thisSpriteRect, RECT otherSpriteRect)
{
	// declare rectangles for intersection test
	RECT tempRect;

	// perform the intersection test
	if (IntersectRect(&tempRect, &thisSpriteRect, &otherSpriteRect))
		return true;
	else
		return false;
}


RECT Player::GetPlayerBounds()
{
	return playerBounds;
}

cInputMgr* Player::GetInput()
{
	return m_InputMgr; 
}

