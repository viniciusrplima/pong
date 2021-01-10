#include "TexturesHolder.h"

sf::Texture &TexturesHolder::getTexture(const std::string &filename)
{
    auto found = _textures.find(filename);

    if (found == _textures.end())
    {
        std::unique_ptr<sf::Texture> texture(new sf::Texture);
        texture->loadFromFile(filename);
        _textures.insert(std::make_pair(filename, std::move(texture)));

        return *_textures.find(filename)->second;
    }
    else
        return *found->second;
}

void TexturesHolder::clear()
{
    _textures.clear();
}

std::map<std::string, std::unique_ptr<sf::Texture>> TexturesHolder::_textures;