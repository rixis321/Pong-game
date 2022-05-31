#pragma once
#include "State.h"
#include "Playing_state.h"
#include "Main_menu.h"
#include "Button.h"
#include "Option_state.h"
#include "SinglePlayer.h"
import Utilities;
class Pause_state : public State	
{
	
private:
	sf::Font font;
	size_t optionIndex;
	std::vector<Button*> buttons;
	sf::RectangleShape backgroundShape;
	sf::Text _winnerText;
	bool flag;
	int ai;
public:
	virtual void Update(const float dt);
	virtual void Draw(const float dt);
	virtual void Input();
	void UpdateButtons();
	
	Pause_state(Game *game);
	Pause_state(Game* game,sf::Text& winner);
	Pause_state(Game* game, int a);
	Pause_state(Game* game, sf::Text& winner, int a);
	~Pause_state();
};

