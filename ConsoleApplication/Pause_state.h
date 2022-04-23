#pragma once
#include "State.h"
#include "Playing_state.h"
#include "Main_menu.h"
#include "Button.h"
class Pause_state : public State	
{
	
private:
	sf::Font font;
	size_t optionIndex;
	std::vector<Button*> buttons;
	sf::RectangleShape backgroundShape;
	sf::Text _winnerText;
	bool flag;
public:
	virtual void Update(const float dt);
	virtual void Draw(const float dt);
	virtual void Input();
	void UpdateButtons();
	
	Pause_state(Game *game);
	Pause_state(Game* game,sf::Text& winner);
	~Pause_state();
};

