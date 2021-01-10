#include "AISystem.h"

AISystem::AISystem()
{
}

AISystem::~AISystem()
{
}

void AISystem::update(EntityContainer *entities, float elapsed)
{
    for (auto &e : entities->getEntityList())
    {
        auto ai = e->get<AIComponent>();

        if (ai)
        {
            ai->update(&(*e), elapsed);
        }
    }
}