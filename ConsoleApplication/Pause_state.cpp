#include "Pause_state.h"
#include "Button.h"


void Pause_state::Update(const float dt)
{
	this->UpdateButtons();
}

void Pause_state::Draw(const float dt)
{
	this->game->window->draw(backgroundShape);
	this->game->window->draw(_winnerText);
	for (int i = 0; i < buttons.size(); i++)
	{
		this->buttons[i]->Draw(this->game->window);
	}
}


void Pause_state::Input()
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

			else if (event.key.code == sf::Keyboard::Return)
			{
				if (optionIndex == 0)
				{
					if (flag)
					{
						this->game->pushState(new Playing_state(game));
						break;
					}
					else
					{
						this->game->popState();
						break;
					}
					
				}
				else if (optionIndex == 1)
				{
					if (flag)
					{
						this->game->pushState(new Main_menu(game));
						break;
					}
					else
					{
						this->game->pushState(new Playing_state(game));
						break;
					}
					
				}
				else if (optionIndex == 2)
				{
					this->game->pushState(new Main_menu(game));
					break;
				}

			}
			else if (event.key.code == sf::Keyboard::Escape)
			 {
				 this->game->popState();
				 break;
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

void Pause_state::UpdateButtons()
{

		if (this->buttons.empty())
			return;

		this->buttons[optionIndex]->Update();

}

Pause_state::Pause_state(Game* game)
{
	this->State::game = game;
	font.loadFromFile("textures/gol.ttf");

	backgroundShape.setFillColor(sf::Color(82, 98, 137, 50));
	backgroundShape.setSize(sf::Vector2f(250,575));
	backgroundShape.setPosition(280, 13);

	this->buttons.push_back(new Button(backgroundShape.getSize().x /2 + 180 , backgroundShape.getSize().y /2 - 50, 200, 50, &font, "Resume", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(backgroundShape.getSize().x / 2 + 180, backgroundShape.getSize().y /2 + 30, 200, 50, &font, "Reset", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(backgroundShape.getSize().x / 2 + 180, backgroundShape.getSize().y / 2 + 110, 200, 50, &font, "Back to main menu", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
}

Pause_state::Pause_state(Game* game, sf::Text& winner)
{
	flag = true;
	this->State::game = game;
	font.loadFromFile("textures/gol.ttf");

	_winnerText = winner;
	_winnerText.setCharacterSize(30);
	_winnerText.setPosition(backgroundShape.getSize().x / 2 + 280, backgroundShape.getSize().y / 2 + 70);

	backgroundShape.setFillColor(sf::Color(82, 98, 137, 50));
	backgroundShape.setSize(sf::Vector2f(250, 575));
	backgroundShape.setPosition(280, 13);

	this->buttons.push_back(new Button(backgroundShape.getSize().x / 2 + 180, backgroundShape.getSize().y / 2 - 50, 200, 50, &font, "Reset", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(backgroundShape.getSize().x / 2 + 180, backgroundShape.getSize().y / 2 + 30, 200, 50, &font, "Back to main menu", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
}



Pause_state::~Pause_state()
{
	for (auto& it : buttons)
	{
		delete it;
	}
}
