#include "PositionComponent.h"

PositionComponent::PositionComponent(float x, float y) : _position(x, y)
{
}

PositionComponent::~PositionComponent()
{
}

sf::Vector2f PositionComponent::getPosition()
{
    return _position;
}

void PositionComponent::setPosition(float x, float y)
{
    _position = sf::Vector2f(x, y);
}