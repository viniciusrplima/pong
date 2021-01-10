#include <SFML/Graphics.hpp>
#include <map>

#include "Entity.h"
#include "EntityContainer.h"
#include "systems/RenderSystem.h"
#include "systems/PhysicSystem.h"
#include "systems/GuiSystem.h"
#include "systems/AISystem.h"
#include "../utils/Logger.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#ifndef _SCENE_H_
#define _SCENE_H_

class Scene : private Logger
{
public:
    Scene();
    Scene(const std::string &, int, int);
    ~Scene();

    void mainLoop();
    void update();
    void render();

    void addEntity(Entity *);
    void onKeyPressed(const std::string &, luabridge::LuaRef);
    void onKeyReleased(const std::string &, luabridge::LuaRef);
    void safeOnKeyPressed(const std::string &, luabridge::LuaRef);
    void reset();
    void destroy();

    b2World *getWorld();

private:
    void updateEvents(const sf::Event &);
    void keypressEvent(const sf::Event &);
    void keyreleaseEvent(const sf::Event &);

private:
    sf::RenderWindow _window;
    sf::Clock _clock;

    std::map<sf::Keyboard::Key, luabridge::LuaRef> _keypressActions;
    std::map<sf::Keyboard::Key, luabridge::LuaRef> _keyreleaseActions;
    std::map<sf::Keyboard::Key, luabridge::LuaRef> _safeKeypressActions;

    EntityContainer *_entities;
    RenderSystem *_renderer;
    PhysicSystem *_physics;
    GuiSystem *_guiSystem;
    AISystem *_aiSystem;

    static unsigned int _numScenes;
};

#endif