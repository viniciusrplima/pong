#include "../Component.h"
#include <SFML/Graphics.hpp>

#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

class RenderComponent : public Component
{
public:
    virtual void render(sf::RenderTarget &, sf::RenderStates) = 0;

    std::type_index getClass() { return std::type_index(typeid(RenderComponent)); }
};

#endif