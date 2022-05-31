#pragma once
#include "State.h"
#include <stack>
#include "TextureManager.h"
#include <fstream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Paddle.h"
#include "Field.h"
#include "Ball.h"
#include <thread>
import Config_file;

class State;

class Game
{
private:
	void loadTextures();
public:
	std::stack<State*> states;
	sf::RenderWindow *window;
	TextureManager texmgr;
	sf::Sprite background, player, playing_field, splash_screen, sp_ball;

	void pushState(State* state);
	void popState();
	void changeState(State* state);
	State* peekState();

	void gameLoop();

	Game();
	~Game();

};

