#include "Exception.h"

Exception::Exception()
{
}

Exception::Exception(const std::string &message)
{
    _message = message;
}

Exception::~Exception()
{
}

std::string Exception::getMessage()
{
    return _message;
}