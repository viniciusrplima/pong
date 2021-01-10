#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <map>

#ifndef _TEXTURES_HOLDER_H_
#define _TEXTURES_HOLDER_H_

class TexturesHolder
{
public:
    static sf::Texture &getTexture(const std::string &);
    static void clear();

private:
    static std::map<std::string, std::unique_ptr<sf::Texture>> _textures;
};

#endif