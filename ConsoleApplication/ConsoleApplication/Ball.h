#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.h"
#include "Paddle.h"
#include <cmath>
#include <iostream>
#include <string>


# define M_PI           3.14159265358979323846

class Ball
{
	

private:
	sf::Sprite _spriteBall;
	int _angle;
	float _speed;
	float _maxSpeed = 400.0f;
	sf::Rect<float> _constraints;
	float _timeElapsed;
	
	std::string _tabScore[3] = { "NIKT", "PRAWY","LEWY" };
	
	

public:
	std::string score = _tabScore[0];
	bool _isOut = false;
	Ball(sf::Rect<float> constraints,sf::Sprite sprite);
	void Update(float const dt);
	void Draw(sf::RenderWindow* target);
	void setPosition(float x, float y);
	void CollideWith(Paddle* paddle);
	bool isOut();
	void setDefaultSpeed();
	std::string getScore();
	sf::Rect<float> getBounds();
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();



};

