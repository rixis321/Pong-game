#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
class TextureManager
{
private:
	std::map<std::string, sf::Texture> textures;

public:
	void loadTextures(const std::string&name, const std::string& filename);

	sf::Texture& getRef(const std::string& texture);

	TextureManager() {};

};

