#include "RenderSystem.h"
#include "../components/RenderComponent.h"
#include "../components/PhysicComponent.h"

#define WORLD_SCALE 100

RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::render(sf::RenderTarget &target, EntityContainer *entities)
{
    sf::Transform transform;

    // change coordinates format
    sf::Vector2u size = target.getSize();
    transform.translate(size.x / 2, size.y / 2);

    // turn up down for physics purpose
    transform.scale(WORLD_SCALE, -WORLD_SCALE);

    for (auto &entity : entities->getEntityList())
    {
        sf::Transform entityTransform(transform);

        auto physicComponent = entity->get<PhysicComponent>();
        auto renderComponent = entity->get<RenderComponent>();

        if (physicComponent)
        {
            b2Vec2 position = physicComponent->getPosition();
            float angle = 180.0f / 3.14159f * physicComponent->getBody()->GetAngle();
            entityTransform.translate(position.x, position.y);
            entityTransform.rotate(angle);
        }

        if (renderComponent)
        {
            renderComponent->render(target, entityTransform);
        }
    }
}