#include "../RenderComponent.h"

#include <SFML/Graphics.hpp>
#include <string>

#ifndef _SPRITE_RENDER_COMPONENT_H_
#define _SPRITE_RENDER_COMPONENT_H_

class SpriteRenderComponent : public RenderComponent
{
public:
    SpriteRenderComponent(float, float, const std::string &);
    ~SpriteRenderComponent();

    void render(sf::RenderTarget &, sf::RenderStates);

private:
    sf::Sprite _sprite;
    sf::Vector2u _textureSize;
    std::string _textureFile;
    bool _loaded;

    float _width;
    float _height;
};

#endif