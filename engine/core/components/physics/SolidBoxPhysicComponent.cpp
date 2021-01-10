#include "SolidBoxPhysicComponent.h"

SolidBoxPhysicComponent::SolidBoxPhysicComponent(
    b2World *world, Entity *entity, float x, float y, float w, float h)
    : _width(w), _height(h), _position(x, y)
{
    initBody(world, entity);
}

SolidBoxPhysicComponent::~SolidBoxPhysicComponent()
{
}

b2Body *SolidBoxPhysicComponent::getBody()
{
    return _body;
}

b2Vec2 SolidBoxPhysicComponent::getPosition()
{
    return _body->GetPosition();
}

void SolidBoxPhysicComponent::initBody(b2World *world, Entity *entity)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(_position.x, _position.y);
    bodyDef.userData.pointer = (uintptr_t)entity;
    b2Body *body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(_width / 2, _height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 100.0f;
    fixtureDef.friction = 0.0f;

    body->CreateFixture(&fixtureDef);

    _body = body;
}