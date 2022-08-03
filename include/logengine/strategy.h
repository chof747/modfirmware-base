#ifndef lOGENGINE_STRATEGY_H
#define lOGENGINE_STRATEGY_H

#include "../logengine.h"

namespace ModFirmWare
{
    class LogEngineStrategy
    {
    public:
        LogEngineStrategy(LogEngine::levelType logLevel) : logLevel(logLevel) {}
        virtual void log(LogEngine::levelType level, const char *component, const char *message, va_list args) = 0;

    protected:
        LogEngine::levelType logLevel;
    };
};

#endif // lOGENGINE_SERIAL_H