#include "configstore.h"

#ifdef ARDUINO_ARCH_ESP32
#include "./configstore/esp32.hpp"
#elif defined ARDUINO_ARCH_ESP8266
#include "./configstore/esp8266.hpp"
#else
#define here
#endif
