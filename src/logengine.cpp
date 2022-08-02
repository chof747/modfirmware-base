#include "logengine.h"
#include <Arduino.h>

using namespace ModFirmWare;

LogEngine* LogEngine::_instance = nullptr;
LogEngine::levelType LogEngine::MAINLOGLEVEL = LogEngine::levelType::WARN;

const char *LEVEL_LABELS[5] = { "NONE", "ERROR", "WARNING", "INFO", "DEBUG"};

LogEngine* LogEngine::getInstance()
//****************************************************************************************
{
    if(nullptr == _instance)
    {
        _instance = new LogEngine(MAINLOGLEVEL);
    }

    return _instance;
}

void LogEngine::log(levelType level, const char* component, const char* message, va_list args)
//****************************************************************************************
{
    if (levelType::NONE != this->logLevel)
    {   
        //Serial.printf("Log-level: %d, given: %d\n", this->logLevel, level);
        if (this->logLevel >= level)
        {
            char buffer[255];
            vsnprintf(buffer,254,message, args);
            Serial.printf("[%-7s][%-10s] %s\n", LEVEL_LABELS[level], component, buffer);
        }
    }
}

LogEngine::LogEngine(levelType loglevel)
//****************************************************************************************
{
    this->logLevel = logLevel;
    if (LogEngine::NONE != logLevel)
    {
        Serial.begin(115200); 
    }
}

