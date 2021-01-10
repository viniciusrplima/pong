#include "PhysicSystem.h"
#include "../components/PhysicComponent.h"
#include "ContactListener.h"
#include <iostream>

PhysicSystem::PhysicSystem()
{
    setupWorld();
}

PhysicSystem::~PhysicSystem()
{
    delete _world;
}

void PhysicSystem::update(EntityContainer *_entities, float elapsed)
{
    int velocityIterations = 6;
    int positionIterations = 2;

    _world->Step(elapsed, velocityIterations, positionIterations);
}

void PhysicSystem::setupWorld()
{
    b2Vec2 gravity(0.0f, 0.0f);
    _world = new b2World(gravity);
    _world->SetContactListener(new ContactListener());
}

void PhysicSystem::clear()
{
    delete _world;
    setupWorld();
}

b2World *PhysicSystem::getWorld()
{
    return _world;
}
