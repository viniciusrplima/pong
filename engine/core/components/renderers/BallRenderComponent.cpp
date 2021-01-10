#include "BallRenderComponent.h"

BallRenderComponent::BallRenderComponent(float r, sf::Color color)
    : _radius(r), _color(color)
{
}

BallRenderComponent::~BallRenderComponent()
{
}

void BallRenderComponent::render(sf::RenderTarget &target, sf::RenderStates states)
{
    sf::CircleShape circle(_radius);
    circle.setFillColor(_color);

    // adjust circle to center position
    sf::Transform transform;
    transform.translate(-_radius, -_radius);
    states.transform *= transform;

    target.draw(circle, states);
}