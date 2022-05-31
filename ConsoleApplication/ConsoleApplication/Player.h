#pragma once
#include "Paddle.h"
class Player
{

public:

	std::string profile_name;
	Paddle* paddle;


	void setName(std::string name);
	Player();
	~Player();


};

