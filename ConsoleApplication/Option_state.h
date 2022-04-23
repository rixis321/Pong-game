#pragma once
#include "Game.h"
#include "Button.h"

class Option_state: public State
{
private:
	sf::Font font;
	std::vector<Button*> buttons;
	size_t optionIndex;
	sf::Text player1_title, player2_title, moveUp_p1, moveDown_p1, moveUp_p2, moveDown_p2;
public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void UpdateButtons();
	Option_state(Game* game);
	~Option_state();
};

