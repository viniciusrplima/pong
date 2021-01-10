#include <string>
#include "lua.hpp"

#include "../utils/Logger.h"

#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine : public Logger
{
public:
    Engine();
    ~Engine();

    void init(const std::string &);

private:
    void exportLuaClasses(lua_State *state);
};

#endif
