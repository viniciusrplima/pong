#include "../Component.h"
#include <SFML/Graphics.hpp>

#ifndef _GUI_COMPONENT_H_
#define _GUI_COMPONENT_H_

class GuiComponent : public Component
{
public:
    virtual void render(sf::RenderTarget &, sf::RenderStates) = 0;

    std::type_index getClass() { return std::type_index(typeid(GuiComponent)); }
};

#endif