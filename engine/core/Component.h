#include <typeindex>

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class Component
{
public:
    virtual ~Component()
    {
    }

    virtual std::type_index getClass()
    {
        return std::type_index(typeid(Component));
    }
};

#endif