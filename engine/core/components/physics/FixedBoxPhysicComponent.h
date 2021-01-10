#include "../PhysicComponent.h"
#include "../../Entity.h"

#ifndef _BOX_PHYSIC_COMPONENT_H_
#define _BOX_PHYSIC_COMPONENT_H_

class FixedBoxPhysicComponent : public PhysicComponent
{
public:
    FixedBoxPhysicComponent(b2World *, Entity *, float, float, float, float);
    ~FixedBoxPhysicComponent();

    b2Body *getBody();
    b2Vec2 getPosition();

private:
    void initBody(b2World *, Entity *);

private:
    b2Body *_body;
    float _width;
    float _height;
    b2Vec2 _position;
};

#endif