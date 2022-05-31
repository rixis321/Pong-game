#pragma once
#include "State.h"
#include "Player.h"
#include "Ai.h"
#include "Pause_state.h"

import Utilities;
class SinglePlayer:public State
{
private:
	Ai* computer;
	Player* player;
	Field* field;
	Ball* ball;
	sf::Font _scoreFont;
	sf::Text _scoreText, _countText, _endGameText;
	int player1_score = 0;
	int player2_score = 0;
	bool isDone;
	float _countDown = 4;
	std::vector<sf::Keyboard::Key> controls;
public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void defualtSettings();
	SinglePlayer(Game* game);
	~SinglePlayer();
};

