#include <string>

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

class Exception
{
public:
    Exception();
    Exception(const std::string &);
    ~Exception();

    std::string getMessage();

private:
    std::string _message;
};

#endif