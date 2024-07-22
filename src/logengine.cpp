#include "logengine.h"
#include "logengine/strategy.h"
#include <Arduino.h>

using namespace ModFirmWare;

LogEngine *LogEngine::_instance = nullptr;

LogEngine *LogEngine::getInstance()
//****************************************************************************************
{
    if (nullptr == _instance)
    {
        _instance = new LogEngine();
    }

    return _instance;
}

size_t LogEngine::addStrategy(LogEngineStrategy *loggingStrategy)
//****************************************************************************************
{
    strategies.push_back(loggingStrategy);
    return strategies.size();
}

void LogEngine::log(levelType level, const char *component, const char *message, va_list args)
//****************************************************************************************
{
    for (size_t i = 0; i < strategies.size(); i++)
    {
        if (nullptr != strategies[i])
        {
            strategies[i]->log(level, component, message, args);
        }
    }
}

LogEngine::LogEngine(): strategies()
//****************************************************************************************
{
}