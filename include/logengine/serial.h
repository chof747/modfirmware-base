#ifndef lOGENGINE_SERIAL_H
#define lOGENGINE_SERIAL_H

#include "strategy.h"

namespace ModFirmWare
{
    class LogEngineSerial: public LogEngineStrategy
    {
        public:
        LogEngineSerial(LogEngine::levelType logLevel, int bau_rate=115200);
        virtual void log(LogEngine::levelType level, const char *component, const char *message, va_list args);
    };
};

#endif //lOGENGINE_SERIAL_H