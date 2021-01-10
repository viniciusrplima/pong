#include "../../utils/Exception.h"

#ifndef _CONTACT_NULL_USER_DATA_EXCEPTION_H_
#define _CONTACT_NULL_USER_DATA_EXCEPTION_H_

class ContactNullUserDataException : public Exception
{
public:
    ContactNullUserDataException(const std::string &message = "")
        : Exception("ContactNullUserDataException: " + message) {}
};

#endif