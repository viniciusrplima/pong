#include "PhysicManipulator.h"
#include "../components/PhysicComponent.h"
#include "../utils/WithoutPhysicComponentException.h"
#include "../components/CollisionEventComponent.h"

PhysicManipulator::PhysicManipulator() : Logger("PhysicManipulator")
{
}

PhysicManipulator::~PhysicManipulator()
{
}

void PhysicManipulator::changeVelocity(Entity *entity, float dx, float dy)
{
    auto physics = getPhysics(entity);

    physics->getBody()->SetLinearVelocity(b2Vec2(dx, dy));
}

void PhysicManipulator::changeAngularSpeed(Entity *entity, float speed)
{
    auto physics = getPhysics(entity);

    physics->getBody()->SetAngularVelocity(speed);
}

void PhysicManipulator::onCollision(Entity *entity, luabridge::LuaRef callback)
{
    entity->addComponent(new CollisionEventComponent(callback));
}

LuaVec2f PhysicManipulator::getPosition(Entity *entity)
{
    auto physics = getPhysics(entity);
    auto position = physics->getPosition();

    return LuaVec2f(position.x, position.y);
}

LuaVec2f PhysicManipulator::getVelocity(Entity *entity)
{
    auto physics = getPhysics(entity);
    auto velocity = physics->getBody()->GetLinearVelocity();

    return LuaVec2f(velocity.x, velocity.y);
}

PhysicComponent *PhysicManipulator::getPhysics(Entity *entity)
{
    auto physics = entity->get<PhysicComponent>();

    if (!physics)
        throw new WithoutPhysicComponentException(
            "Entity " + entity->getKind() + " dont have physic component");

    return physics;
}