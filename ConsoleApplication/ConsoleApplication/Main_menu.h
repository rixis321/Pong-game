#pragma once
#include "State.h"
#include "Playing_state.h"
#include "Button.h"
#include <vector>
#include "Option_state.h"
#include "SplashScreen.h"
#include "SinglePlayer.h"
import Utilities;
class Main_menu: public State
{
private:
	sf::Font font;
	std::vector<Button*> buttons;
	size_t optionIndex;
	sf::Text profile_text;

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void UpdateButtons();

	Main_menu(Game* game, std::string profile);
	Main_menu(Game* game);
	~Main_menu();
};

