#include "Ai.h"

void Ai::runAi(Ball*ball)
{
	float centerY = (this->paddle->getTop() + this->paddle->getBottom() / 2);

	if (ball->getBottom() > this->paddle->getBottom())
	{
		this->paddle->_direction = this->paddle->DOWN;
	}
	else if (ball->getTop() < this->paddle->getTop())
	{
		this->paddle->_direction = this->paddle->UP;
	}
	else
	{
		this->paddle->_direction = this->paddle->NONE;
	}
}


Ai::Ai()
{
	this->paddle = new Paddle;
}

Ai::~Ai()
{
	delete paddle;
}
