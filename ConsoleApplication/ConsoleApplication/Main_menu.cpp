#include "Main_menu.h"

void Main_menu::Draw(const float dt)
{
	this->game->window->draw(this->game->background);
	
	for (int i = 0; i < buttons.size(); i++)
	{
		this->buttons[i]->Draw(this->game->window);
	}

	this->game->window->draw(this->profile_text);
	/*this->game->window->draw(gameTitle);
	this->game->window->draw(sp_playButton);
	this->game->window->draw(mp_playButton);*/

	
}
void Main_menu::Update(const float dt)
{
	this->UpdateButtons();

}

void Main_menu::Input()
{
	sf::Event event;

	while (this->game->window->pollEvent(event))
	{


		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->window->close();
				break;
			}

			else if (event.key.code == sf::Keyboard::Up)
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

			else if (event.key.code == sf::Keyboard::Return)
			{
				if (optionIndex == 0)
				{
					this->game->pushState(new SinglePlayer(game));

				}
				else if (optionIndex == 1)
				{
					this->game->pushState(new Playing_state(game));
				}
				else if (optionIndex == 2)
				{
					this->game->pushState(new Option_state(game));
					break;
				}
				else if (optionIndex == 3)
				{
					this->game->changeState(new SplashScreen(game));
					break;
				}
				else if (optionIndex == 4)
				{
					{
						this->game->window->close();
						break;
					}
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
	
		}
	
	}

}

void Main_menu::UpdateButtons()
{
	if (this->buttons.empty())
		return;

	this->buttons[optionIndex]->Update();
	
}

Main_menu::Main_menu(Game* game)
{
	this->game = game;
	font.loadFromFile("textures/gol.ttf");
	this->buttons.push_back(new Button(this->game->window->getSize().y/2 - 10, this->game->window->getSize().x / 2 - 300, 250, 50, &font, "Singleplayer", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 200, 250, 50, &font, "Multiplayer", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 100, 250, 50, &font, "Settings", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2, 250, 50, &font, "Exit", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	
	
	

	
}
Main_menu::Main_menu(Game* game,std::string profile)
{
	this->game = game;
	

	
	font.loadFromFile("textures/gol.ttf");
	this->profile_text.setFont(font);
	this->profile_text.setString("Logged as " + profile);
	this->profile_text.setCharacterSize(20);
	this->profile_text.setPosition(20, 20);
	setProfileName(profile);

	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 300, 250, 50, &font, "Singleplayer", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 200, 250, 50, &font, "Multiplayer", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 - 100, 250, 50, &font, "Settings", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2, 250, 50, &font, "Log out", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 10, this->game->window->getSize().x / 2 + 100, 250, 50, &font, "Exit", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));





}

Main_menu::~Main_menu()
{
	for (auto& it : buttons)
	{
		delete it;
	}

}
