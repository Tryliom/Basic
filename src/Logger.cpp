#include "Logger.h"

#include <iostream>

namespace Logger
{
    void Log(const std::string& message)
    {
        std::cout << message << " from " << __LINE__ << std::endl;
    }

    void LogError(const std::string& message)
    {
        std::cout << "[ERROR] " << message << " from " << __LINE__ << std::endl;
    }
}