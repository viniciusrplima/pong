#include "LuaUtils.h"
#include "Exception.h"

bool CheckLua(lua_State *L, int r)
{
    if (r != LUA_OK)
    {
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
    }
    return true;
}

sf::Color LuaColors::getColor(const std::string &color)
{
    auto found = _luaColors.find(color);

    if (found != _luaColors.end())
        return found->second;

    return sf::Color::Black;
}

const std::map<std::string, sf::Color> LuaColors::_luaColors{
    {"blue", sf::Color::Blue},
    {"red", sf::Color::Red},
    {"black", sf::Color::Black},
    {"green", sf::Color::Green},
    {"blue", sf::Color::Blue},
    {"white", sf::Color::White},
    {"yellow", sf::Color::Yellow},
    {"magenta", sf::Color::Magenta},
    {"cyan", sf::Color::Cyan},
    {"transparent", sf::Color::Transparent},
};

sf::Keyboard::Key LuaKeys::getKey(const std::string &key)
{
    auto found = _luaKeys.find(key);

    if (found == _luaKeys.end())
        throw new Exception(key + " key undefined");

    return found->second;
}

const std::map<std::string, sf::Keyboard::Key> LuaKeys::_luaKeys{
    {"up", sf::Keyboard::Up},
    {"down", sf::Keyboard::Down},
    {"left", sf::Keyboard::Left},
    {"right", sf::Keyboard::Right},
    {"enter", sf::Keyboard::Return},
    {"esc", sf::Keyboard::Escape},
    {"space", sf::Keyboard::Space},
    {"a", sf::Keyboard::A},
    {"b", sf::Keyboard::B},
    {"c", sf::Keyboard::C},
    {"d", sf::Keyboard::D},
    {"e", sf::Keyboard::E},
    {"f", sf::Keyboard::F},
    {"g", sf::Keyboard::G},
    {"h", sf::Keyboard::H},
    {"i", sf::Keyboard::I},
    {"j", sf::Keyboard::J},
    {"k", sf::Keyboard::K},
    {"l", sf::Keyboard::L},
    {"m", sf::Keyboard::M},
    {"n", sf::Keyboard::N},
    {"o", sf::Keyboard::O},
    {"p", sf::Keyboard::P},
    {"q", sf::Keyboard::Q},
    {"r", sf::Keyboard::R},
    {"s", sf::Keyboard::S},
    {"t", sf::Keyboard::T},
    {"u", sf::Keyboard::U},
    {"v", sf::Keyboard::V},
    {"w", sf::Keyboard::W},
    {"x", sf::Keyboard::X},
    {"y", sf::Keyboard::Y},
    {"z", sf::Keyboard::Z},
};

LuaVec2f::LuaVec2f(float _x, float _y) : x(_x), y(_y)
{
}