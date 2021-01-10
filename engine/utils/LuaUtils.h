#include <iostream>
#include "lua.hpp"
#include <map>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>

#ifndef _LUA_UTILS_H_
#define _LUA_UTILS_H_

bool CheckLua(lua_State *L, int r);

class LuaColors
{
public:
    static sf::Color getColor(const std::string &color);

private:
    static const std::map<std::string, sf::Color> _luaColors;
};

class LuaKeys
{
public:
    static sf::Keyboard::Key getKey(const std::string &key);

private:
    static const std::map<std::string, sf::Keyboard::Key> _luaKeys;
};

struct LuaVec2f
{
    LuaVec2f(float, float);

    float x;
    float y;
};

#endif