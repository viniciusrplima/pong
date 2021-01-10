#include <box2d/box2d.h>

#include "../EntityContainer.h"

#ifndef _PHYSIC_SYSTEM_H_
#define _PHYSIC_SYSTEM_H_

class PhysicSystem
{
public:
    PhysicSystem();
    ~PhysicSystem();

    void update(EntityContainer *, float elapsed);
    void clear();

    b2World *getWorld();

private:
    void setupWorld();

    b2World *_world;
};

#endif