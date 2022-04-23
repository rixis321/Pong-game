#include "Paddle.h"



void Paddle::Input(sf::Event *event)
{
		if (event->type == sf::Event::KeyReleased)
		{

			_direction = NONE;

		}
	 else if (event->type == sf::Event::KeyPressed)
	{
		if (event->key.code == goingUp)
		{
			_direction = UP;
		}
		else if (event->key.code == goingDown)
		{
			_direction = DOWN;
		}
	}
}

void Paddle::Update(const float dt)
{	

	float velocity = 0.0f;

	if (_direction == UP)
	{
		velocity = speed * -1;
	}

	else if (_direction == DOWN)
	{
		velocity = speed;
	}

	_playerSprite.move(0, velocity * dt);
	
	sf::Vector2<float> playerPosition = _playerSprite.getPosition();

	if (playerPosition.y < _fieldRect.top + 15)
	{
		_playerSprite.setPosition(playerPosition.x, _fieldRect.top + 15);
	}
	else if (playerPosition.y + _playerSprite.getTexture()->getSize().y > _fieldRect.top + _fieldRect.height - 15)
	{
		_playerSprite.setPosition(playerPosition.x, _fieldRect.top + _fieldRect.height - _playerSprite.getTexture()->getSize().y - 15);
	}
	
	
	
}


void Paddle::Init(sf::Sprite sprite,const sf::Vector2f vect,sf::Keyboard::Key upKey,sf::Keyboard::Key downKey, sf::FloatRect rect)
{

	goingUp = upKey;
	goingDown = downKey;
	_playerSprite = sprite;
	_playerSprite.setPosition(vect.x, vect.y);
	_fieldRect = rect;
}

void Paddle::setPosition(float x, float y)
{
	_playerSprite.setPosition(x, y);
}

sf::FloatRect Paddle::getBounds()
{
	return _playerSprite.getGlobalBounds();
}

float Paddle::getTop()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top;
}

float Paddle::getBottom()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top + boudingRect.height;
}

sf::Vector2f Paddle::getPosition()
{
	return _playerSprite.getPosition();
}

void Paddle::Draw(sf::RenderWindow *window)
{
	window->draw(_playerSprite);
}















