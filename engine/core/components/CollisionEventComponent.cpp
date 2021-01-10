#include "CollisionEventComponent.h"

CollisionEventComponent::CollisionEventComponent(luabridge::LuaRef callback) : _callback(callback)
{
}

CollisionEventComponent::~CollisionEventComponent()
{
}

void CollisionEventComponent::trigger(const std::string &kind)
{
    _callback(kind);
}