#pragma once
#include "Game.h"


class Game;

class State
{
public:

	Game* game;
	virtual void Input() = 0;
	virtual void Update(const float dt) = 0;
	virtual void Draw(const float dt ) = 0;


};

