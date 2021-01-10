#include "Entity.h"
#include <iostream>
#include <memory>

Entity::Entity() : Entity("nil")
{
}

Entity::Entity(const std::string &kind) : _kind(kind)
{
}

Entity::~Entity()
{
    _components.clear();
}

void Entity::addComponent(Component *component)
{
    std::unique_ptr<Component> comp(component);
    _components.insert(std::make_pair(component->getClass(), std::move(comp)));
}

std::string Entity::getKind() const
{
    return _kind;
}