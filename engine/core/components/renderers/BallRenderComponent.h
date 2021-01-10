#include "../RenderComponent.h"

#ifndef _BALL_RENDER_COMPONENT_H_
#define _BALL_RENDER_COMPONENT_H_

class BallRenderComponent : public RenderComponent
{
public:
    BallRenderComponent(float, sf::Color);
    ~BallRenderComponent();

    void render(sf::RenderTarget &, sf::RenderStates);

private:
    float _radius;
    sf::Color _color;
};

#endif