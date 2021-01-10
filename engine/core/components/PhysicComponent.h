#include <box2d/box2d.h>

#include "../Component.h"

#ifndef _PHYSIC_COMPONENT_H_
#define _PHYSIC_COMPONENT_H_

class PhysicComponent : public Component
{
public:
    virtual b2Vec2 getPosition() = 0;
    virtual b2Body *getBody() = 0;

    std::type_index getClass() { return std::type_index(typeid(PhysicComponent)); }
};

#endif