#include "BoxRenderComponent.h"

BoxRenderComponent::BoxRenderComponent(float w, float h, sf::Color color)
    : _width(w), _height(h), _color(color)
{
}

BoxRenderComponent::~BoxRenderComponent()
{
}

void BoxRenderComponent::render(sf::RenderTarget &target, sf::RenderStates states)
{
    sf::RectangleShape box(sf::Vector2f(_width, _height));
    box.setFillColor(_color);

    // adjust rectangle to center position
    sf::Transform transform;
    transform.translate(-_width / 2, -_height / 2);
    states.transform *= transform;

    target.draw(box, states);
}