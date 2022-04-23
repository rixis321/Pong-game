#include "Button.h"
#include <iostream>


Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor,sf::Color hoverColor, sf::Color activeColor)
{
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->buttonState = IDLE;



	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width /2.f) - this->text.getGlobalBounds().width/2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
		
	


	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}

void Button::Draw(sf::RenderWindow *target)
{
	target->draw(this->shape);
	target->draw(this->text);
}

void Button::Update()
{
	this->buttonState = IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->buttonState = HOVER;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->buttonState = ACTIVE;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->buttonState = HOVER;

	}
	switch (this->buttonState)
	{
	case IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		
		break;
	}
}

bool Button::isPressed()
{
	if (this->buttonState == ACTIVE)
		return true;
	
	return false;
}



