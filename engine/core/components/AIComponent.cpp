#include "AIComponent.h"

AIComponent::AIComponent(luabridge::LuaRef behavior) : _behavior(behavior)
{
}

AIComponent::~AIComponent()
{
}

void AIComponent::update(Entity *entity, float elapsed)
{
    _behavior(entity, elapsed);
}
