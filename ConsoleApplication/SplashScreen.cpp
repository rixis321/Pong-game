#include "SplashScreen.h"



void SplashScreen::Draw(const float dt)
{
	this->game->window->draw(this->game->splash_screen);
}

void SplashScreen::Update(const float dt)
{
}

void SplashScreen::Input()
{
	sf::Event event;

	while (this->game->window->pollEvent(event))
	{
		switch (event.type)
		{

			case sf::Event::KeyPressed:
			{
			this->game->pushState(new Main_menu(game));

			}

		default: break;
		}
	}
}

SplashScreen::SplashScreen(Game* game)
{
	this->game = game;
}
