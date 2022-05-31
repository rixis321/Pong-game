#include "SplashScreen.h"



void SplashScreen::Draw(const float dt)
{
	this->game->window->draw(this->game->splash_screen);
	for (int i = 0; i < buttons.size(); i++)
	{
		this->buttons[i]->Draw(this->game->window);
	}
	this->game->window->draw(this->player_input);

}

void SplashScreen::Update(const float dt)
{
	this->UpdateButtons();
}

void SplashScreen::Input()
{
	sf::Event event;

	while (this->game->window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Up)
			{

				if (optionIndex > 0)
				{
					optionIndex--;
				}
				else
				{
					optionIndex = buttons.size() - 1;
				}
			}

			else if (event.key.code == sf::Keyboard::Down)
			{
				if (optionIndex < buttons.size() - 1)
				{
					optionIndex++;
				}
				else
					optionIndex = 0;

			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->window->close();
				break;
			}

			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (optionIndex == 0)
				{
					this->game->pushState(new ProfileManager(game));
				}
				else if (optionIndex == 1)
				{
					this->game->pushState(new ProfileManager(game, true));
				}
			}

		}

	}

}		
			


void SplashScreen::UpdateButtons()
{
	if (this->buttons.empty())
		return;

	this->buttons[optionIndex]->Update();
}

SplashScreen::SplashScreen(Game* game)
{
	font.loadFromFile("textures/gol.ttf");
	this->create_prof = true;
	this->load_prof = false;

	this->player = new Player;
	this->player_input.setCharacterSize(12);
	this->player_input.setFont(font);


	this->game = game;
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 150, 250, 50, &font, "Create profile", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 -50 , 250, 50, &font, "Load profile", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
}

SplashScreen::~SplashScreen()
{
	delete player;

	for (auto& it : buttons)
	{
		delete it;
	}
}
