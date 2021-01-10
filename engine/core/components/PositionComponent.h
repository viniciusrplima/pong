#include <SFML/Graphics.hpp>
#include "../Component.h"

#ifndef _POSITION_COMPONENT_H_
#define _POSITION_COMPONENT_H_

class PositionComponent : public Component
{
public:
    PositionComponent(float, float);
    ~PositionComponent();

    sf::Vector2f getPosition();
    void setPosition(float, float);

    std::type_index getClass()
    {
        return std::type_index(typeid(PositionComponent));
    }

private:
    sf::Vector2f _position;
};

#endif