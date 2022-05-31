#pragma once
#include "State.h"
#include "Main_menu.h"
#include "Button.h"
#include "Player.h"
#include "ProfileManager.h"
class SplashScreen :public State
{
private:

	sf::Font font;
	std::vector<Button*> buttons;
	size_t optionIndex;
	sf::Text player_input;
	Player* player;
	bool create_prof, load_prof;
	
public:

	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();
	void UpdateButtons();

	SplashScreen(Game* game);
	~SplashScreen();
};

