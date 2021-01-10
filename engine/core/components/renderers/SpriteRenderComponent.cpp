#include "SpriteRenderComponent.h"
#include "../../TexturesHolder.h"

SpriteRenderComponent::SpriteRenderComponent(
    float width, float height,
    const std::string &filename)

    : _width(width),
      _height(height),
      _sprite(),
      _loaded(false),
      _textureFile(filename)
{
}

SpriteRenderComponent::~SpriteRenderComponent()
{
}

void SpriteRenderComponent::render(sf::RenderTarget &target, sf::RenderStates states)
{
    if (!_loaded)
    {
        _sprite.setTexture(TexturesHolder::getTexture(_textureFile));
        _loaded = true;
    }

    sf::Vector2u texSize = _sprite.getTexture()->getSize();

    // adjust sprite to center position
    sf::Transform transform;
    transform.translate(-_width / 2, -_height / 2);

    // adjust size of sprite
    float scaleX = _width / texSize.x;
    float scaleY = _height / texSize.y;
    transform.scale(sf::Vector2f(scaleX, scaleY));

    states.transform *= transform;

    target.draw(_sprite, states);
}
