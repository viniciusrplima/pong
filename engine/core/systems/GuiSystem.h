#include "../Entity.h"
#include "../EntityContainer.h"
#include <SFML/Graphics.hpp>

#ifndef _GUI_SYSTEM_H_
#define _GUI_SYSTEM_H_

class GuiSystem
{
public:
    GuiSystem();
    ~GuiSystem();

    void render(sf::RenderTarget &, EntityContainer *);
};

#endif