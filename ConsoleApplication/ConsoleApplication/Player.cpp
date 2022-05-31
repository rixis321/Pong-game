#include "Player.h"

void Player::setName(std::string name)
{
	this->profile_name = name;
}

Player::Player()
{
	this->paddle = new Paddle;

}

Player::~Player()
{
	delete paddle;
}
