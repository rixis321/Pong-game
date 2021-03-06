#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"

class Paddle
{
private:
	
	sf::Sprite _playerSprite;
	sf::Keyboard::Key goingUp, goingDown;
	sf::FloatRect _fieldRect;
	float speed = 300.0f;

	

public:
	enum Direction { NONE, UP, DOWN };
	Direction _direction = NONE;
	float getTop();
	float getBottom();
	sf::Vector2f getPosition();
	sf::FloatRect getBounds();
	void Input(sf::Event *event);
	void Update(const float dt);
	void Draw(sf::RenderWindow* window);
	void Init(sf::Sprite sprite,const sf::Vector2f vect, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::FloatRect rect);
	void Init(sf::Sprite sprite, const sf::Vector2f vect, sf::FloatRect rect);
	void setPosition(float x, float y);

};

