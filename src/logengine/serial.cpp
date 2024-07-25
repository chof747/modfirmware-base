#include "logengine/serial.h"
#include <Arduino.h>

using namespace ModFirmWare;

const char *LEVEL_LABELS[5] = {"NONE", "ERROR", "WARNING", "INFO", "DEBUG"};

LogEngineSerial::LogEngineSerial(LogEngine::levelType logLevel, int baud_rate) : LogEngineStrategy(logLevel), baudRate(baud_rate)
//****************************************************************************************
{
}

void LogEngineSerial::initialize()
//****************************************************************************************
{
    if (LogEngine::NONE != logLevel)
    {
        Serial.begin(baudRate);
        while (!Serial)
        {
            ;
        }
        delay(100);
        log(LogEngine::DEBUG, "SERIAL", "Communication established with %d bps !", baudRate);
    }
}

void LogEngineSerial::log(LogEngine::levelType level, const char *component, const char *message, ...)
//****************************************************************************************
{
    va_list args;
    va_start(args, message);
    this->log(level, component, message, args);
    va_end(args);
}

void LogEngineSerial::log(LogEngine::levelType level, const char *component, const char *message, va_list args)
//****************************************************************************************
{
    if (LogEngine::levelType::NONE != this->logLevel)
    {
        // Serial.printf("Log-level: %d, given: %d\n", this->logLevel, level);
        if (this->logLevel >= level)
        {
            char buffer[255];
            vsnprintf(buffer, 254, message, args);
            Serial.printf("[%-7s][%-10s] %s\n", LEVEL_LABELS[level], component, buffer);
        }
    }
}