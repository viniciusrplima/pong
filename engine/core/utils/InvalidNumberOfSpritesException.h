#include "../../utils/Exception.h"

#ifndef _INVALID_NUMBER_OF_SPRITES_EXCEPTION_H_
#define _INVALID_NUMBER_OF_SPRITES_EXCEPTION_H_

class InvalidNumberOfSpritesException : public Exception
{
public:
    InvalidNumberOfSpritesException(const std::string &message)
        : Exception("InvalidNumberOfSpritesException: " + message) {}
};

#endif