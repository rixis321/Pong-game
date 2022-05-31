#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"


class Field
{
private:
	sf::Sprite _fieldSprite;
public:
	void Init(sf::Sprite sprite);
	void Draw(sf::RenderWindow *window);
	sf::FloatRect getBounds();
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
	
};

