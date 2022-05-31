#pragma once
#include "Paddle.h"
#include "Ball.h"
class Ai
{	
public:

	Paddle* paddle;
	void runAi(Ball*ball);

	Ai();
	~Ai();
};

