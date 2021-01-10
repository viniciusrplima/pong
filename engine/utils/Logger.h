#include <iostream>

#ifndef _LOGGER_H_
#define _LOGGER_H_

class Logger
{
public:
    Logger(const std::string &);
    ~Logger();

    void info(const std::string &);
    void success(const std::string &);
    void error(const std::string &);

private:
    std::string tag();

private:
    std::string _module;
};

#endif