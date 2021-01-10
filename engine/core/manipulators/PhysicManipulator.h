#include <box2d/box2d.h>
#include <memory>

#include "../Entity.h"
#include "../components/PhysicComponent.h"
#include "../../utils/Logger.h"
#include "../../utils/LuaUtils.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#ifndef _PHYSIC_MANIPULATOR_H_
#define _PHYSIC_MANIPULATOR_H_

class PhysicManipulator : private Logger
{
public:
    PhysicManipulator();
    ~PhysicManipulator();

    void changeVelocity(Entity *, float, float);
    void changeAngularSpeed(Entity *, float);
    void onCollision(Entity *entity, luabridge::LuaRef);
    LuaVec2f getPosition(Entity *);
    LuaVec2f getVelocity(Entity *);

private:
    PhysicComponent *getPhysics(Entity *);
};

#endif