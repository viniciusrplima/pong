#include <SFML/Graphics.hpp>
#include "../EntityContainer.h"

#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

class RenderSystem
{
public:
    RenderSystem();
    ~RenderSystem();

    void render(sf::RenderTarget &, EntityContainer *);
};

#endif