#pragma once
#include "State.h"
#include <Windows.h>
#include "Pause_state.h"
#include "Main_menu.h"
#include "Player.h"
#include <thread>
import Utilities;

class Playing_state:public State
{
private:
	Player* player1;
	Player* player2;
	Field* field;
	Ball* ball;
	sf::Font _scoreFont;
	sf::Text _scoreText, _countText, _endGameText;
	int player1_score = 0;
	int player2_score = 0;
	float _countDown = 4;
	bool isDone;
	std::vector<sf::Keyboard::Key> controls;
	
public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void defualtSettings();
	
	Playing_state(Game * game);
	~Playing_state();
};

