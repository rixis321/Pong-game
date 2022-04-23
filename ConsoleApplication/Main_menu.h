#pragma once
#include "State.h"
#include "Playing_state.h"
#include "Button.h"
#include <vector>
#include "Option_state.h"
class Main_menu: public State
{
private:
	sf::Font font;
	void loadgame();
	std::vector<Button*> buttons;
	size_t optionIndex;

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void UpdateButtons();

	Main_menu(Game* game);
	~Main_menu();
};

