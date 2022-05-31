#pragma once
#include "State.h"
#include "SplashScreen.h"
#include "Player.h"
#include <filesystem>
#include <thread>
import Utilities;

class ProfileManager: public State
{
private:
	sf::RectangleShape rec;
	std::vector<Button*> buttons;
	//std::vector<Button*> players_profile;
	size_t optionIndex;
	sf::Font font;
	std::vector<Player*> players;
	Player* player;
	sf::Keyboard::Key key;
	sf::Text player_input, text_box;
	bool check, isValid, isExist, load_mode;

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();

	void loadDataFromFile();
	void saveToFile();
	bool checkProfile(std::string name);
	void UpdateButtons();
	void loadProfiles();
	ProfileManager(Game *game);
	ProfileManager(Game* game, bool mode);
	~ProfileManager();
};

