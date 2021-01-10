#include "FixedBoxPhysicComponent.h"

FixedBoxPhysicComponent::FixedBoxPhysicComponent(
    b2World *world, Entity *entity, float x, float y, float w, float h)
    : _width(w), _height(h), _position(x, y)
{
    initBody(world, entity);
}

FixedBoxPhysicComponent::~FixedBoxPhysicComponent()
{
}

b2Body *FixedBoxPhysicComponent::getBody()
{
    return _body;
}

b2Vec2 FixedBoxPhysicComponent::getPosition()
{
    return _body->GetPosition();
}

void FixedBoxPhysicComponent::initBody(b2World *world, Entity *entity)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(_position.x, _position.y);
    bodyDef.userData.pointer = (uintptr_t)entity;
    b2Body *body = world->CreateBody(&bodyDef);

    b2PolygonShape staticBox;
    staticBox.SetAsBox(_width / 2, _height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);

    _body = body;
}