#include <string>
#include <map>
#include <typeindex>
#include <memory>

#include "Component.h"

#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
public:
    Entity();
    Entity(const std::string &);
    ~Entity();

    void addComponent(Component *);

    std::string getKind() const;

private:
    std::string _kind;
    std::map<std::type_index, std::unique_ptr<Component>> _components;

public:
    template <class Type>
    Type *get()
    {
        auto it = _components.find(std::type_index(typeid(Type)));

        if (it != _components.end())
            return static_cast<Type *>(&(*it->second));

        return nullptr;
    }
};

#endif