#include "Playing_state.h"


void Playing_state::Draw(const float dt)
{
	
	this->field->Draw(this->game->window);
	
	this->paddle1->Draw(this->game->window);
	this->paddle2->Draw(this->game->window);
	this->ball->Draw(this->game->window);
	this->game->window->draw(_scoreText);
	this->game->window->draw(_countText);

	
}

void Playing_state::Update(const float dt)
{
	if (isDone) return;
	//this->c1 -= dt;
	//std::cout << this->c1 << std::endl;

	//this->count_down -= dt;
	//std::cout << this->count_down << std::endl;

	this->paddle1->Update(dt);
	this->paddle2->Update(dt);
	this->ball->Update(dt);
	if (this->ball->getBounds().intersects(paddle1->getBounds()))
	{
		ball->CollideWith(paddle1);
	}
	if (this->ball->getBounds().intersects(paddle2->getBounds()))
	{
		ball->CollideWith(paddle2);
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
		this->paddle1->setPosition(40, 300);
		this->paddle2->setPosition(740, 300);
	}

	if (player1_score == 3 or player2_score == 3)
	{
		isDone = true;

		_endGameText.setString(player1_score == 3 ? "Player 1 has won" : "Player 2 has won");
		
		this->game->pushState(new Pause_state(game, _endGameText));
	}
	

	
	
	
}

void Playing_state::Input()
{
	sf::Event event;
	
	while (this->game->window->pollEvent(event))
	{
		
		this->paddle1->Input(&event);
		this->paddle2->Input(&event);

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->pushState(new Pause_state(game));
				
			}
		}
		
	}


		
	
}

Playing_state::Playing_state(Game* game)
{
	this->game = game;
	this->paddle1 = new Paddle;
	this->paddle2 = new Paddle;
	this->field = new Field;
	this->field->Init(this->game->playing_field);

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
	

	this->paddle1->Init(this->game->player,{40,300},sf::Keyboard::W,sf::Keyboard::S,this->field->getBounds());
	this->paddle2->Init(this->game->player, {740,300 },sf::Keyboard::Up,sf::Keyboard::Down, this->field->getBounds());

	
	
	sf::Rect<float> ballRect = sf::Rect<float>(this->field->getLeft() + 10,this->field->getTop() + 10, this->field->getBounds().width - 20, this->field->getBounds().height - 20);
	this->ball = new Ball(ballRect, this->game->sp_ball);
	//float centerX = this->field->getLeft() +  this->field->getBounds().width/ 2 ;
	//float centerY = this->field->getTop() + this->field->getBounds().height / 2
	ball->setPosition(400,300);
	
}

Playing_state::~Playing_state()
{
	delete paddle1;
	delete paddle2;
	delete field;
	delete ball;
}
