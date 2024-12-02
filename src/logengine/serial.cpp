#include "logengine/serial.h"
#include <Arduino.h>

#ifndef SERIAL_TIMEOUT
#define SERIAL_TIMEOUT 1000
#endif

Stream *ModFirmWare::usbCDCHelper(int baudRate)
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    Stream* serial;

    Serial.begin(baudRate);
    Serial1.begin(baudRate, 44, 43);

    time_t startMillis = millis();
    while ((!Serial) && ((millis() - startMillis) < SERIAL_TIMEOUT))
    {
        delay(10);
    }

    if (Serial)
    {
        serial = &Serial;
        //serial->println("Using Serial for serial communication");
    }
    else
    {
        serial = &Serial1;
        //serial->println("Using Serial1 for serial communication");
    }

    return serial;
#else
    Serial.begin(baudRate);
    return &Serial;
#endif
}

using namespace ModFirmWare;

const char *LEVEL_LABELS[5] = {"NONE", "ERROR", "WARNING", "INFO", "DEBUG"};

LogEngineSerial::LogEngineSerial(LogEngine::levelType logLevel, int baud_rate) : LogEngineStrategy(logLevel), baudRate(baud_rate), serial(NULL)
//****************************************************************************************
{
}

LogEngineSerial::LogEngineSerial(LogEngine::levelType logLevel, Stream *serial) : LogEngineStrategy(logLevel), serial(serial)
//****************************************************************************************
{
}

void LogEngineSerial::initialize()
//****************************************************************************************
{

    if (LogEngine::NONE != logLevel)
    {
        if (NULL == serial)
        {
            Serial.begin(baudRate);
            time_t now = millis();
            while ((!Serial) && (SERIAL_TIMEOUT > (millis() - now)))
            {
                delay(10);
            }
            serial = &Serial;
            delay(100);
        }
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
            serial->printf("[%-7s][%-10s] %s\n", LEVEL_LABELS[level], component, buffer);
        }
    }
}
