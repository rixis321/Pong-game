#include "TextureManager.h"

void TextureManager::loadTextures(const std::string& name, const std::string& filename)
{
    sf::Texture tex;
    tex.loadFromFile(filename);

   this->textures[name] = tex;
}

sf::Texture& TextureManager::getRef(const std::string& texture)
{
    return this->textures.at(texture);
}
