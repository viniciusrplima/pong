#include "BallPhysicComponent.h"
#include <iostream>

BallPhysicComponent::BallPhysicComponent(b2World *world, Entity *entity, float r)
    : _radius(r)
{
    initBody(world, entity);
}

BallPhysicComponent::~BallPhysicComponent()
{
}

b2Body *BallPhysicComponent::getBody()
{
    return _body;
}

b2Vec2 BallPhysicComponent::getPosition()
{
    return _body->GetPosition();
}

void BallPhysicComponent::initBody(b2World *world, Entity *entity)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    bodyDef.userData.pointer = (uintptr_t)entity;
    b2Body *body = world->CreateBody(&bodyDef);

    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = _radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicCircle;
    fixtureDef.density = 1.0f;
    fixtureDef.restitution = 1.0f;
    fixtureDef.friction = 0.0f;

    body->CreateFixture(&fixtureDef);

    _body = body;
}