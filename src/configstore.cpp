#include "configstore.h"

using namespace ModFirmWare;

#ifdef ARDUINO_ARCH_ESP32
#include "./configstore/esp32.hpp"
#elif defined ARDUINO_ARCH_ESP8266
#include "./configstore/esp8266.hpp"
#else
#define here
#endif

ConfigStore* ConfigStore::_instance = nullptr;


ConfigStore* ConfigStore::getInstance(const char* prefNameSpace)
{
     if(nullptr == _instance)
    {
        _instance = new ConfigStore(prefNameSpace);
    }

    return _instance;
}