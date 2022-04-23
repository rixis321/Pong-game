#pragma once
#include "State.h"
#include "Main_menu.h"
class SplashScreen :public State
{

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();

	SplashScreen(Game* game);
};

