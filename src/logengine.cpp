#include "logengine.h"
#include "logengine/strategy.h"
#include <Arduino.h>

using namespace ModFirmWare;

LogEngine* LogEngine::_instance = nullptr;

LogEngine* LogEngine::getInstance(int numLoggers)
//****************************************************************************************
{
    if(nullptr == _instance)
    {
        _instance = new LogEngine(numLoggers);
    }

    return _instance;
}

int LogEngine::addStrategy(LogEngineStrategy* loggingStrategy)
//****************************************************************************************
{
    for (int i = 0; i < numLoggers; i++)
    {
        if (nullptr == strategies[i])
        {
            strategies[i] = loggingStrategy;
            return i;
        }
    }

    return -1;
}


void LogEngine::log(levelType level, const char *component, const char *message, va_list args)
//****************************************************************************************
{
    for (int i = 0; i < numLoggers; i++)
    {
        if (nullptr != strategies[i])
        {
            strategies[i]->log(level,component,message,args);
        }
    }
}

LogEngine::LogEngine(int numLoggers)
//****************************************************************************************
{
    strategies = new LogEngineStrategy*[numLoggers];
    for (int i = 0; i < numLoggers; i++)
    {
        strategies[i] = 0;
    }
      
    this->numLoggers = numLoggers;
}