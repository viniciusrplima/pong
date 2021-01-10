#include "ContactListener.h"
#include "../Entity.h"
#include "../utils/ContactNullUserDataException.h"
#include "../components/CollisionEventComponent.h"

#include <iostream>

ContactListener::ContactListener()
{
}

ContactListener::~ContactListener()
{
}

void ContactListener::BeginContact(b2Contact *contact)
{
    Entity *entityA = (Entity *)contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    Entity *entityB = (Entity *)contact->GetFixtureB()->GetBody()->GetUserData().pointer;

    if (!(entityA && entityB))
        throw new ContactNullUserDataException("bodies must have entity as user data");

    auto eventCompA = entityA->get<CollisionEventComponent>();
    auto eventCompB = entityB->get<CollisionEventComponent>();

    if (eventCompA)
        eventCompA->trigger(entityB->getKind());

    if (eventCompB)
        eventCompB->trigger(entityA->getKind());
}