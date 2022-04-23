#pragma once
#include "State.h"
#include <Windows.h>
#include "Pause_state.h"
#include "Main_menu.h"

class Playing_state:public State
{
private:
	Paddle *paddle1;
	Paddle *paddle2;
	Field* field;
	Ball* ball;
	sf::Font _scoreFont;
	sf::Text _scoreText, _countText, _endGameText;
	int player1_score = 0;
	int player2_score = 0;
	float _countDown = 4;
	bool isDone;

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	
	Playing_state(Game * game);
	~Playing_state();
};

