#pragma once

#include <string>

namespace Logger
{
    void Log(const std::string& message);
    void LogError(const std::string& message);
}