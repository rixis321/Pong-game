#include "Field.h"



void Field::Init(sf::Sprite sprite)
{
	_fieldSprite = sprite;
	_fieldSprite.setPosition(0, 0);
}

void Field::Draw(sf::RenderWindow *window)
{
	window->draw(this->_fieldSprite);
}

sf::FloatRect Field::getBounds()
{
	return _fieldSprite.getGlobalBounds();
}

float Field::getTop()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top;
}

float Field::getBottom()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.top + boudingRect.height;
}

float Field::getLeft()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.left;
}

float Field::getRight()
{
	sf::Rect<float> boudingRect = getBounds();
	return boudingRect.left + boudingRect.width;
}

