#include "Logger.h"

Logger::Logger(const std::string &module) : _module(module)
{
}

Logger::~Logger()
{
}

void Logger::info(const std::string &msg)
{
    std::cout << tag() << "INFO: " << msg << std::endl;
}

void Logger::success(const std::string &msg)
{
    std::cout << "\033[32m" << tag() << "SUCCESS: " << msg << "\033[0m" << std::endl;
}

void Logger::error(const std::string &msg)
{
    std::cout << "\033[31m" << tag() << "ERROR: " << msg << "\033[0m" << std::endl;
}

std::string Logger::tag()
{
    return "[" + _module + "] ";
}