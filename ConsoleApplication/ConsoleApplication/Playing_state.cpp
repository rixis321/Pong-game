#include "Playing_state.h"


void Playing_state::Draw(const float dt)
{
	
	this->field->Draw(this->game->window);
	
	this->player1->paddle->Draw(this->game->window);
	this->player2->paddle->Draw(this->game->window);
	this->ball->Draw(this->game->window);
	this->game->window->draw(_scoreText);
	this->game->window->draw(_countText);

	
}

void Playing_state::Update(const float dt)
{
	if (isDone) return;
	
	this->player1->paddle->Update(dt);
	this->player2->paddle->Update(dt);

	this->ball->Update(dt);
	if (this->ball->getBounds().intersects(this->player1->paddle->getBounds()))
	{
		ball->CollideWith(this->player1->paddle);
	}
	if (this->ball->getBounds().intersects(this->player2->paddle->getBounds()))
	{
		ball->CollideWith(this->player2->paddle);
	}
	
	

	if (this->ball->isOut())
	{
		
		_countText.setFillColor(sf::Color::Blue);
		_countText.setCharacterSize(40);
		this->_countDown-= dt;
		int var = static_cast<int>(this->_countDown);
		
		_countText.setString(std::to_string(var));

		if (this->ball->getScore() == "LEWY")
		{
			 player2_score += 1;
			 this->ball->score = "NIKT";

		}
		else if (this->ball->getScore() == "PRAWY")
		{
			player1_score += 1;
			this->ball->score = "NIKT";
		}

		
		_scoreText.setString(std::to_string(player1_score) + "-" + std::to_string(player2_score));
		
		
		if (this->_countDown < 0.f)
		{
			this->ball->_isOut = false;
			this->_countDown = 4;
			_countText.setFillColor(sf::Color::White);
			_countText.setCharacterSize(0);

		}

		this->ball->setPosition(400, 300);
		this->ball->setDefaultSpeed();
		this->player1->paddle->setPosition(40, 300);
		this->player2->paddle->setPosition(740, 300);
	}

	if (player1_score == 3 or player2_score == 3)
	{
		isDone = true;

		_endGameText.setString(player1_score == 3 ? this->player1->profile_name +" has won" : "Player 2 has won");
		
		this->game->pushState(new Pause_state(game, _endGameText));
	}
	

	
	
	
}

void Playing_state::Input()
{
	sf::Event event;
	
	while (this->game->window->pollEvent(event))
	{
		
		this->player1->paddle->Input(&event);
		this->player2->paddle->Input(&event);

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->pushState(new Pause_state(game));
				
			}
		}
		
	}


		
	
}

void Playing_state::defualtSettings()
{
	controls.push_back(sf::Keyboard::Key::W);
	controls.push_back(sf::Keyboard::Key::S);
	controls.push_back(sf::Keyboard::Key::Up);
	controls.push_back(sf::Keyboard::Key::Down);


}

Playing_state::Playing_state(Game* game)
{
	this->game = game;
	this->player1 = new Player;
	this->player2 = new Player;
	this->field = new Field;
	
	this->field->Init(this->game->playing_field);
	
	controls = getOptions();
	std::thread p1(getOptions);
	p1.join();
	if (controls.empty())
	{
		this->defualtSettings();
	}

	_scoreFont.loadFromFile("textures/gol.ttf");
	_scoreText.setFont(_scoreFont);
	_scoreText.setString("0 - 0");
	_scoreText.setFillColor(sf::Color::Blue);
	_scoreText.setCharacterSize(45);
	_scoreText.setPosition(350, 30);
	
	_countText.setFont(_scoreFont);
	_countText.setString("3");
	_countText.setCharacterSize(0);
	_countText.setPosition(400, 180);
	_countText.setFillColor(sf::Color::White);

	_endGameText.setFont(_scoreFont);
	_endGameText.setString("");
	_endGameText.setCharacterSize(20);
	_endGameText.setFillColor(sf::Color::Blue);
	
	
	this->player1->paddle->Init(this->game->player,{40,300},controls[0], controls[1], this->field->getBounds());
	this->player1->profile_name = getName();
	this->player2->paddle->Init(this->game->player, {740,300 },controls[2], controls[3], this->field->getBounds());
	

	
	
	sf::Rect<float> ballRect = sf::Rect<float>(this->field->getLeft() + 10,this->field->getTop() + 10, this->field->getBounds().width - 20, this->field->getBounds().height - 20);
	this->ball = new Ball(ballRect, this->game->sp_ball);
	ball->setPosition(400,300);
	
}

Playing_state::~Playing_state()
{
	delete player1;
	delete player2;
	delete field;
	delete ball;
}
