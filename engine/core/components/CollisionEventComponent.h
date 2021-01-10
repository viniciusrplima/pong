#include <box2d/box2d.h>

#include "../Component.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#ifndef _COLLISION_EVENT_COMPONENT_H_
#define _COLLISION_EVENT_COMPONENT_H_

class CollisionEventComponent : public Component
{
public:
    CollisionEventComponent(luabridge::LuaRef);
    ~CollisionEventComponent();

    void trigger(const std::string &);

    std::type_index getClass()
    {
        return std::type_index(typeid(CollisionEventComponent));
    }

private:
    luabridge::LuaRef _callback;
};

#endif