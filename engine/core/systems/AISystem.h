#include "../components/AIComponent.h"
#include "../EntityContainer.h"

#ifndef _AI_SYSTEM_H_
#define _AI_SYSTEM_H_

class AISystem
{
public:
    AISystem();
    ~AISystem();

    void update(EntityContainer *, float);
};

#endif