#include "EntityFactory.h"
#include "components/PhysicComponent.h"
#include "components/RenderComponent.h"
#include "components/renderers/BallRenderComponent.h"
#include "components/renderers/BoxRenderComponent.h"
#include "components/renderers/SpriteRenderComponent.h"
#include "components/physics/BallPhysicComponent.h"
#include "components/physics/FixedBoxPhysicComponent.h"
#include "components/physics/SolidBoxPhysicComponent.h"
#include "components/PositionComponent.h"
#include "components/AIComponent.h"

#include "utils/EntityNullException.h"
#include "../utils/LuaUtils.h"

#include <iostream>

EntityFactory::EntityFactory() : Logger("EntityFactory")
{
    error("factory created without scene");
}

EntityFactory::EntityFactory(Scene *scene)
    : _scene(scene), _entityBuilding(nullptr), Logger("EntityFactory")
{
}

EntityFactory::~EntityFactory()
{
}

#define COMPONENT_METHOD(a)           \
    verifyEntity();                   \
    _entityBuilding->addComponent(a); \
    return this;

EntityFactory *EntityFactory::begin(const std::string &name)
{
    _entityBuilding = new Entity(name);
}

EntityFactory *EntityFactory::addBallRender(float radius, const std::string &color){
    COMPONENT_METHOD(new BallRenderComponent(radius, LuaColors::getColor(color)))}

EntityFactory *EntityFactory::addBoxRender(float width, float height, const std::string &color){
    COMPONENT_METHOD(new BoxRenderComponent(width, height, LuaColors::getColor(color)))}

EntityFactory *EntityFactory::addSpriteRender(float width, float height, const std::string &filename){
    COMPONENT_METHOD(new SpriteRenderComponent(width, height, filename))}

EntityFactory *EntityFactory::addBallPhysic(float radius){
    COMPONENT_METHOD(new BallPhysicComponent(_scene->getWorld(), _entityBuilding, radius))}

EntityFactory *EntityFactory::addBoxPhysic(float x, float y, float w, float h){
    COMPONENT_METHOD(new SolidBoxPhysicComponent(_scene->getWorld(), _entityBuilding, x, y, w, h))}

EntityFactory *EntityFactory::addFixedBoxPhysic(float x, float y, float w, float h){
    COMPONENT_METHOD(new FixedBoxPhysicComponent(_scene->getWorld(), _entityBuilding, x, y, w, h))}

EntityFactory *EntityFactory::addBehavior(luabridge::LuaRef behavior){
    COMPONENT_METHOD(new AIComponent(behavior))}

Entity *EntityFactory::build()
{
    Entity *entity = _entityBuilding;
    _entityBuilding = nullptr;
    _scene->addEntity(entity);
    return entity;
}

DisplayComponent *EntityFactory::createDisplay(
    const std::vector<std::string> &textures,
    float size,
    float distance,
    float x,
    float y)
{
    Entity *entity = new Entity("Display");
    entity->addComponent(new PositionComponent(x, y));
    auto display = new DisplayComponent(textures, size, distance);
    entity->addComponent(display);
    _scene->addEntity(entity);
    return display;
}

void EntityFactory::verifyEntity()
{
    if (_entityBuilding == nullptr)
        throw new EntityNullException("error building entity");
}