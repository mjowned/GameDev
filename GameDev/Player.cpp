#include "Player.h"

Player::Player() { }

Player::~Player() { }

Entity* Player::EmptyClone()
{
	return new Player();
}
void Player::setBody(b2Body* _body)
{
	body = _body;
}

b2Body* Player::GetBody()
{
	return body;
}