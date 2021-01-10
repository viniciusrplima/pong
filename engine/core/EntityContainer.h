#include "Entity.h"

#include <vector>
#include <memory>

#ifndef _ENTITY_CONTAINER_H_
#define _ENTITY_CONTAINER_H_

class EntityContainer
{
public:
    EntityContainer();
    ~EntityContainer();

    void addEntity(Entity *);
    void clear();
    const std::vector<std::unique_ptr<Entity>> &getEntityList();

private:
    std::vector<std::unique_ptr<Entity>> _entities;
};

#endif