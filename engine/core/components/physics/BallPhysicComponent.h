#include "../PhysicComponent.h"
#include "../../Entity.h"

#ifndef _BALL_PHYSIC_COMPONENT_H_
#define _BALL_PHYSIC_COMPONENT_H_

class BallPhysicComponent : public PhysicComponent
{

public:
    BallPhysicComponent(b2World *, Entity *, float);
    ~BallPhysicComponent();

    b2Body *getBody();
    b2Vec2 getPosition();

private:
    void initBody(b2World *, Entity *);

private:
    b2Body *_body;
    float _radius;
};

#endif