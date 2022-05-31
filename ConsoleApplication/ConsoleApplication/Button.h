#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <vector>

enum button_states {IDLE, ACTIVE, HOVER};
class Button
{
private:
	int buttonState;
	sf::RectangleShape shape;
	sf::Font *font;

	sf::Color hoverColor;
	sf::Color idleColor;
	sf::Color activeColor;

public:
	sf::Text text;
	Button(float x, float y, float width, float height,
		sf::Font* font,std::string text,sf::Color idleColor,
		sf::Color hoverColor,sf::Color activeColor);
	~Button();
	void Draw(sf::RenderWindow *target);
	void Update();
	bool isPressed();



};

