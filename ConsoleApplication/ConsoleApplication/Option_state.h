#pragma once
#include "Game.h"
#include "Button.h"
#include "Main_menu.h"

import Utilities;

class Option_state: public State
{
private:
	sf::Font font;
	std::vector<Button*> buttons;
	size_t optionIndex;
	sf::Text player1_title, player2_title, moveUp_p1, moveDown_p1, moveUp_p2, moveDown_p2;
	sf::Keyboard::Key input;
	bool pressed = false;
	std::vector<sf::Keyboard::Key> key_binds;
public:
	
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void defaultSettings();
	void UpdateButtons();
	void initKeyBounds();
	Option_state(Game* game);
	~Option_state();
};

