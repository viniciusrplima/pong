#include "EntityContainer.h"

EntityContainer::EntityContainer()
{
}

EntityContainer::~EntityContainer()
{
    _entities.clear();
}

void EntityContainer::addEntity(Entity *entity)
{
    std::unique_ptr<Entity> entptr(entity);
    _entities.push_back(std::move(entptr));
}

void EntityContainer::clear()
{
    _entities.clear();
}

const std::vector<std::unique_ptr<Entity>> &EntityContainer::getEntityList()
{
    return _entities;
}