#include "../Component.h"
#include "../Entity.h"

#include <lua.hpp>
#include "LuaBridge/LuaBridge.h"

#ifndef _AI_COMPONENT_H_
#define _AI_COMPONENT_H_

class AIComponent : public Component
{
public:
    AIComponent(luabridge::LuaRef);
    ~AIComponent();

    void update(Entity *, float);

    std::type_index getClass()
    {
        return std::type_index(typeid(AIComponent));
    }

private:
    luabridge::LuaRef _behavior;
};

#endif