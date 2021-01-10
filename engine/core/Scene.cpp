#include "Scene.h"
#include <thread>
#include <iostream>
#include <cstdlib>

#include "../utils/LuaUtils.h"
#include "../utils/Exception.h"

Scene::Scene() : Scene("untitled", 300, 250)
{
}

Scene::Scene(const std::string &title, int width, int height)
    : _window(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close),
      _clock(),
      _entities(new EntityContainer()),
      _renderer(new RenderSystem()),
      _physics(new PhysicSystem()),
      _guiSystem(new GuiSystem()),
      _aiSystem(new AISystem()),
      Logger("Scene: " + title)
{
    success("scene created");

    Scene::_numScenes++;

    std::thread mainThread(&Scene::mainLoop, this);
    mainThread.detach();
}

Scene::~Scene()
{
    if (_entities != nullptr)
    {
        delete _entities;
        _entities = nullptr;
    }

    if (_renderer != nullptr)
    {
        delete _renderer;
        _renderer = nullptr;
    }

    if (_physics != nullptr)
    {
        delete _physics;
        _physics = nullptr;
    }

    if (_guiSystem != nullptr)
    {
        delete _guiSystem;
        _guiSystem = nullptr;
    }

    info("scene destroyed");

    // exit program when no scene remains
    if (--Scene::_numScenes == 0)
        std::exit(0);
}

void Scene::mainLoop()
{
    while (_window.isOpen())
    {
        try
        {
            sf::Event event;
            while (_window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    _window.close();
                else
                    updateEvents(event);

            update();
            render();
        }
        catch (Exception *err)
        {
            error(err->getMessage());
            _window.close();
        }
    }

    this->~Scene(); // destroy scene when window closes
}

void Scene::render()
{
    _window.clear(sf::Color::Black);
    _renderer->render(_window, _entities);
    _guiSystem->render(_window, _entities);
    _window.display();
}

void Scene::update()
{
    float elapsedTime = _clock.getElapsedTime().asSeconds();
    _clock.restart();

    _physics->update(_entities, elapsedTime);
    _aiSystem->update(_entities, elapsedTime);
}

void Scene::addEntity(Entity *entity)
{
    _entities->addEntity(entity);

    info("added new entity of kind " + entity->getKind());
}

void Scene::onKeyPressed(const std::string &key, luabridge::LuaRef action)
{
    _keypressActions.insert(std::make_pair(LuaKeys::getKey(key), action));
}

void Scene::onKeyReleased(const std::string &key, luabridge::LuaRef action)
{
    _keyreleaseActions.insert(std::make_pair(LuaKeys::getKey(key), action));
}

void Scene::safeOnKeyPressed(const std::string &key, luabridge::LuaRef action)
{
    _safeKeypressActions.insert(std::make_pair(LuaKeys::getKey(key), action));
}

void Scene::reset()
{
    _keypressActions.clear();
    _keyreleaseActions.clear();

    _entities->clear();
    _physics->clear();
}

void Scene::destroy()
{
    _window.close();
}

b2World *Scene::getWorld()
{
    return _physics->getWorld();
}

void Scene::updateEvents(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
        keypressEvent(event);

    if (event.type == sf::Event::KeyReleased)
        keyreleaseEvent(event);
}

void Scene::keypressEvent(const sf::Event &event)
{
    { // unsafe
        auto found = _keypressActions.find(event.key.code);

        if (found != _keypressActions.end())
            found->second(); // execute action
    }

    { // safe
        auto found = _safeKeypressActions.find(event.key.code);

        if (found != _safeKeypressActions.end())
            found->second(); // execute action
    }
}

void Scene::keyreleaseEvent(const sf::Event &event)
{
    auto found = _keyreleaseActions.find(event.key.code);

    if (found != _keyreleaseActions.end())
        found->second(); // execute action
}

unsigned int Scene::_numScenes = 0;