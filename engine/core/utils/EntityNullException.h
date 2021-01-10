#include "../../utils/Exception.h"

#ifndef _ENTITY_NULL_EXCEPTION_H_
#define _ENTITY_NULL_EXCEPTION_H_

class EntityNullException : public Exception
{
public:
    EntityNullException(const std::string &message) : Exception("EntityNullException: " + message) {}
};

#endif