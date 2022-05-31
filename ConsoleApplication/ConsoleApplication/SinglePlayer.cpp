#include "SinglePlayer.h"

void SinglePlayer::Draw(const float dt)
{
	this->field->Draw(this->game->window);

	this->player->paddle->Draw(this->game->window);
	this->computer->paddle->Draw(this->game->window);

	this->ball->Draw(this->game->window);
	this->game->window->draw(_scoreText);
	this->game->window->draw(_countText);
}

void SinglePlayer::Update(const float dt)
{
	if (isDone) return;

	this->player->paddle->Update(dt);
	this->computer->paddle->Update(dt);
	this->ball->Update(dt);
	this->computer->runAi(ball);

	if (this->ball->getBounds().intersects(this->player->paddle->getBounds()))
	{
		ball->CollideWith(this->player->paddle);
	}
	if (this->ball->getBounds().intersects(this->computer->paddle->getBounds()))
	{
		ball->CollideWith(this->computer->paddle);
	}

	if (this->ball->isOut())
	{

		_countText.setFillColor(sf::Color::Blue);
		_countText.setCharacterSize(40);
		this->_countDown -= dt;
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
		this->player->paddle->setPosition(40, 300);
		this->computer->paddle->setPosition(740, 300);
	}

	if (player1_score == 3 or player2_score == 3)
	{
		isDone = true;

		_endGameText.setString(player1_score == 3 ? this->player->profile_name + " has won" : "Player 2 has won");

		this->game->pushState(new Pause_state(game, _endGameText,1));
	}

}

void SinglePlayer::Input()
{
	sf::Event event;

	while (this->game->window->pollEvent(event))
	{

		this->player->paddle->Input(&event);

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->pushState(new Pause_state(game,1));

			}
		}

	}
}

void SinglePlayer::defualtSettings()
{
	controls.push_back(sf::Keyboard::Key::W);
	controls.push_back(sf::Keyboard::Key::S);
	controls.push_back(sf::Keyboard::Key::Up);
	controls.push_back(sf::Keyboard::Key::Down);


}
SinglePlayer::SinglePlayer(Game*game)
{
	this->game = game;
	this->player = new Player;
	this->computer = new Ai;
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

	this->player->paddle->Init(this->game->player, { 40,300 }, controls[0], controls[1], this->field->getBounds());
	this->player->profile_name = getName();
	this->computer->paddle->Init(this->game->player, { 740,300 }, this->field->getBounds());

	sf::Rect<float> ballRect = sf::Rect<float>(this->field->getLeft() + 10, this->field->getTop() + 10, this->field->getBounds().width - 20, this->field->getBounds().height - 20);
	this->ball = new Ball(ballRect, this->game->sp_ball);
	ball->setPosition(400, 300);
}

SinglePlayer::~SinglePlayer()
{
	delete player;
	delete field;
	delete computer;

}
