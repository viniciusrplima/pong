#include "GuiSystem.h"
#include "../components/GuiComponent.h"
#include "../components/PositionComponent.h"

#include <box2d/box2d.h>

GuiSystem::GuiSystem()
{
}

GuiSystem::~GuiSystem()
{
}

void GuiSystem::render(sf::RenderTarget &target, EntityContainer *entities)
{
    sf::Transform transform;

    // change coordinates format
    sf::Vector2u size = target.getSize();
    transform.translate(size.x / 2, size.y / 2);

    for (auto &entity : entities->getEntityList())
    {
        sf::Transform entityTransform(transform);

        auto guiComponent = entity->get<GuiComponent>();
        auto positionComponent = entity->get<PositionComponent>();

        if (positionComponent)
        {
            auto position = positionComponent->getPosition();
            entityTransform.translate(position.x, position.y);
        }

        if (guiComponent)
        {
            guiComponent->render(target, entityTransform);
        }
    }
}