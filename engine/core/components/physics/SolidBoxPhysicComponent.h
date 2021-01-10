#include "../PhysicComponent.h"
#include "../../Entity.h"

#ifndef _SOLID_BOX_PHYSIC_COMPONENT_H_
#define _SOLID_BOX_PHYSIC_COMPONENT_H_

class SolidBoxPhysicComponent : public PhysicComponent
{
public:
    SolidBoxPhysicComponent(b2World *, Entity *, float, float, float, float);
    ~SolidBoxPhysicComponent();

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