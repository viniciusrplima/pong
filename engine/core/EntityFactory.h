#include "Scene.h"
#include "Entity.h"

#include <map>

#include "components/renderers/DisplayComponent.h"

#include "../utils/Logger.h"
#include "../utils/LuaUtils.h"

#ifndef _ENTITY_FACTORY_H_
#define _ENTITY_FACTORY_H_

class EntityFactory : private Logger
{
public:
    EntityFactory();
    EntityFactory(Scene *);
    ~EntityFactory();

    EntityFactory *begin(const std::string &);

    // renderers
    EntityFactory *addBallRender(float, const std::string &);
    EntityFactory *addBoxRender(float, float, const std::string &);
    EntityFactory *addSpriteRender(float, float, const std::string &);

    // physics
    EntityFactory *addBallPhysic(float);
    EntityFactory *addBoxPhysic(float, float, float, float);
    EntityFactory *addFixedBoxPhysic(float, float, float, float);

    // ai
    EntityFactory *addBehavior(luabridge::LuaRef);

    Entity *build();

    DisplayComponent *createDisplay(const std::vector<std::string> &, float, float, float, float);

private:
    void verifyEntity();

private:
    Entity *_entityBuilding;
    Scene *_scene;
};

#endif