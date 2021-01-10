#include "Engine.h"
#include "Scene.h"
#include "Entity.h"
#include "EntityFactory.h"
#include "Component.h"
#include "manipulators/PhysicManipulator.h"
#include "manipulators/SoundManipulator.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"
#include "LuaBridge/Vector.h"
#include "../utils/LuaUtils.h"
#include "../utils/Exception.h"
#include "TexturesHolder.h"
#include "SoundHolder.h"
#include "components/renderers/DisplayComponent.h"

#include <X11/Xlib.h>

Engine::Engine() : Logger("Engine")
{
}

Engine::~Engine()
{
    TexturesHolder::clear();
    SoundHolder::clear();
}

void Engine::init(const std::string &indexFilename)
{
    info("initialized engine");

    XInitThreads(); // avoid thread error

    lua_State *lua = luaL_newstate();
    luaL_openlibs(lua);

    // embed all classes
    exportLuaClasses(lua);

    info("exported classes to lua");

    try
    {
        if (CheckLua(lua, luaL_dofile(lua, "game/main.lua")))
            success("main Lua file executed");
    }
    catch (Exception *err)
    {
        error(err->getMessage());
    }

    while (true)
    {
        // do nothing
    }
}

void Engine::exportLuaClasses(lua_State *lua)
{

    luabridge::
        getGlobalNamespace(lua)
            // export scene
            .beginClass<Scene>("Scene")
            .addConstructor<void (*)(const std::string &, int, int)>()
            .addFunction("on_key_pressed", &Scene::onKeyPressed)
            .addFunction("on_key_released", &Scene::onKeyReleased)
            .addFunction("safe_on_key_pressed", &Scene::safeOnKeyPressed)
            .addFunction("reset", &Scene::reset)
            .addFunction("destroy", &Scene::destroy)
            .endClass()

            // export factory
            .beginClass<EntityFactory>("EntityFactory")
            .addConstructor<void (*)(Scene *)>()
            .addFunction("begin", &EntityFactory::begin)
            .addFunction("build", &EntityFactory::build)
            .addFunction("add_ball_render", &EntityFactory::addBallRender)
            .addFunction("add_ball_physic", &EntityFactory::addBallPhysic)
            .addFunction("add_box_render", &EntityFactory::addBoxRender)
            .addFunction("add_box_physic", &EntityFactory::addBoxPhysic)
            .addFunction("add_fixed_box_physic", &EntityFactory::addFixedBoxPhysic)
            .addFunction("add_sprite_render", &EntityFactory::addSpriteRender)
            .addFunction("add_behavior", &EntityFactory::addBehavior)
            .addFunction("create_display", &EntityFactory::createDisplay)
            .endClass()

            // export entity
            .beginClass<Entity>("Entity")
            .endClass()

            // export lua vector
            .beginClass<LuaVec2f>("LuaVec2f")
            .addProperty("x", &LuaVec2f::x)
            .addProperty("y", &LuaVec2f::y)
            .endClass()

            // export display component
            .beginClass<DisplayComponent>("DisplayComponent")
            .addFunction("set_values", &DisplayComponent::setValues)
            .endClass()

            // export physic manipulator
            .beginClass<PhysicManipulator>("PhysicManipulator")
            .addConstructor<void (*)(void)>()
            .addFunction("change_velocity", &PhysicManipulator::changeVelocity)
            .addFunction("change_angular_speed", &PhysicManipulator::changeAngularSpeed)
            .addFunction("on_collision", &PhysicManipulator::onCollision)
            .addFunction("get_position", &PhysicManipulator::getPosition)
            .addFunction("get_velocity", &PhysicManipulator::getVelocity)
            .endClass()

            // export sound manipulator
            .beginClass<SoundManipulator>("SoundManipulator")
            .addConstructor<void (*)(void)>()
            .addFunction("play", &SoundManipulator::play)
            .endClass();
}
