#include "../../utils/Exception.h"

#ifndef _WITHOUT_PHYSIC_COMPONENT_EXCEPTION_H_
#define _WITHOUT_PHYSIC_COMPONENT_EXCEPTION_H_

class WithoutPhysicComponentException : public Exception
{
public:
    WithoutPhysicComponentException(const std::string &message)
        : Exception("WithoutPhysicComponentException: " + message) {}
};

#endif