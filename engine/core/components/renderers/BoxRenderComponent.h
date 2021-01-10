#include "../RenderComponent.h"

#ifndef _BOX_RENDER_COMPONENT_H_
#define _BOX_RENDER_COMPONENT_H_

class BoxRenderComponent : public RenderComponent
{
public:
    BoxRenderComponent(float w, float h, sf::Color);
    ~BoxRenderComponent();

    void render(sf::RenderTarget &, sf::RenderStates);

private:
    float _width;
    float _height;
    sf::Color _color;
};

#endif