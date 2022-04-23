#include "Ball.h"


Ball::Ball(sf::Rect<float> constraints, sf::Sprite sprite)
{
	_spriteBall = sprite;
	//_spriteBall.setPosition(100, 100);
	_speed = 150.0f;
	_angle = rand() % 2 == 0 ? 0 : 180;
	_constraints = constraints;
	score = _tabScore[0];
	_timeElapsed = 0;
}

void Ball::Update(float const dt)
{
	if (_isOut) return;

	_timeElapsed += dt;
	if (_timeElapsed < 1) return;
	score = _tabScore[0];
	//if (isOut) return;
	float velocity = _speed * dt;
	float angleInRadian = _angle * M_PI / 180.0f;

	float velocityX = velocity * std::cos(angleInRadian) - 0 * std::sin(angleInRadian);
	float velocityY = 0 * std::cos(angleInRadian) + velocity * std::sin(angleInRadian);
	
	
	
	if (getTop() + velocityY <= _constraints.top or getBottom() + velocityY >= _constraints.top + _constraints.height)
	{
		
		_angle = 360 - _angle;
		velocityY *= -1;
	}

	if (getLeft() + velocityX <= _constraints.left)
	{
		
		_angle = (180 - _angle) % 360;
		velocityX *= -1;
		score = _tabScore[2];
		_isOut = true;
		
	}
	else if (getRight() + velocityX >= _constraints.left + _constraints.width)
	{
		_angle = (180 - _angle) % 360;
		velocityX *= -1;
		score = _tabScore[1];
		_isOut = true;
		
	}
	/*if (getLeft() + velocityX <= _constraints.left)
	{
		score = _tabScore[2];
		std::cout << "LEWY WIN" << std::endl;
	}
	if (getRight() + velocityX >= _constraints.left + _constraints.width )
	{
		score = _tabScore[1];
		std::cout << "PRAWY WIN" << std::endl;
	}*/
	_spriteBall.move(velocityX, velocityY);
}


void Ball::Draw(sf::RenderWindow* target)
{
	target->draw(this->_spriteBall);
}

void Ball::setPosition(float x, float y)
{
		_spriteBall.setPosition(x, y);
	
}

void Ball::CollideWith(Paddle* paddle)
{
	
	float paddleCenterY = (paddle->getTop() + paddle->getBottom()) / 2;
	float ballCenterY = (this->getTop() + this->getBottom()) / 2;

	float distDiff = ballCenterY - paddleCenterY;
	float maxDiff = paddle->getBounds().height;

	float normalizedDiff = distDiff / maxDiff;


	if (paddle->getPosition().x < 400)
	{
		_angle = (int)(normalizedDiff * 90);
	}
	else
		_angle = 180 -  (int)(normalizedDiff * 90);

	
	_speed += 50;

	if (_speed > _maxSpeed)
		_speed = _maxSpeed;
}

bool Ball::isOut()
{
	return _isOut;
}

void Ball::setDefaultSpeed()
{
	_speed = 150.0f;
}

std::string Ball::getScore()
{
	return score;
}









sf::Rect<float> Ball::getBounds()
{
	return _spriteBall.getGlobalBounds();
}

float Ball::getTop()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top;
}

float Ball::getBottom()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top + boudingRect.height;
}

float Ball::getLeft()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.left;
}

float Ball::getRight()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.left + boudingRect.width;
}
