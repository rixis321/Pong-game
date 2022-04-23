#include "Option_state.h"

void Option_state::Draw(const float dt)
{
	this->game->window->clear();
	this->game->window->draw(this->game->background);

	this->game->window->draw(player1_title);
	this->game->window->draw(player2_title);
	this->game->window->draw(moveUp_p1);
	this->game->window->draw(moveDown_p1);
	this->game->window->draw(moveUp_p2);
	this->game->window->draw(moveDown_p2);
	
	for (int i = 0; i < buttons.size(); i++)
	{
		this->buttons[i]->Draw(this->game->window);
	}
}

void Option_state::Update(const float dt)
{
	this->UpdateButtons();
}

void Option_state::Input()
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
					
				}
				else if (optionIndex == 1)
				{

				}
				else if (optionIndex == 2)
				{

				}
				else if (optionIndex == 3)
				{

				}
				else if (optionIndex == 4)
				{

				}
				else if (optionIndex == 5)
				{
					this->game->popState();
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

void Option_state::UpdateButtons()
{
	if (this->buttons.empty())
		return;

	this->buttons[optionIndex]->Update();
}

Option_state::Option_state(Game* game)
{
	this->game = game;
	font.loadFromFile("textures/gol.ttf");

	player1_title.setFont(font);
	player2_title.setFont(font);
	moveDown_p1.setFont(font);
	moveDown_p2.setFont(font);
	moveUp_p1.setFont(font);
	moveUp_p2.setFont(font);

	player1_title.setString("Player 1 keybinds ");
	player1_title.setFillColor(sf::Color::Blue);
	player1_title.setPosition(100, 50);

	moveUp_p1.setString("move up ");
	moveUp_p1.setFillColor(sf::Color::Blue);
	moveUp_p1.setPosition(120, 110);
	moveUp_p1.setCharacterSize(20);

	moveDown_p1.setString("move down ");
	moveDown_p1.setFillColor(sf::Color::Blue);
	moveDown_p1.setPosition(120, 180);
	moveDown_p1.setCharacterSize(20);

	player2_title.setString("Player 2 keybinds ");
	player2_title.setFillColor(sf::Color::Blue);
	player2_title.setPosition(500, 50);

	moveUp_p2.setString("move up ");
	moveUp_p2.setFillColor(sf::Color::Blue);
	moveUp_p2.setPosition(530, 110);
	moveUp_p2.setCharacterSize(20);

	moveDown_p2.setString("move down ");
	moveDown_p2.setFillColor(sf::Color::Blue);
	moveDown_p2.setPosition(530, 180);
	moveDown_p2.setCharacterSize(20);

	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 50, this->game->window->getSize().x / 2 - 300, 70, 50, &font, "W", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 - 50, this->game->window->getSize().x / 2 - 230, 70, 50, &font, "S", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 + 360, this->game->window->getSize().x / 2 - 300, 70, 50, &font, "Up Arrow", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 + 360, this->game->window->getSize().x / 2 - 230, 70, 50, &font, "Down Arrow", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));

	this->buttons.push_back(new Button(this->game->window->getSize().y / 2  , this->game->window->getSize().x / 2 - 100, 250, 50, &font, "restore defualt settings", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	this->buttons.push_back(new Button(this->game->window->getSize().y / 2 , this->game->window->getSize().x / 2 , 250, 50, &font, "back to main menu", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
}

Option_state::~Option_state()
{
	for (auto& it : buttons)
	{
		delete it;
	}
}
