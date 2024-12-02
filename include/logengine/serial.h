#ifndef lOGENGINE_SERIAL_H
#define lOGENGINE_SERIAL_H

#include "strategy.h"

class Stream;

namespace ModFirmWare
{
    class LogEngineSerial: public LogEngineStrategy
    {
        public:
        LogEngineSerial(LogEngine::levelType logLevel, int baud_rate=115200);
        LogEngineSerial(LogEngine::levelType logLevel, Stream* serial);
        virtual void initialize();
        virtual void log(LogEngine::levelType level, const char *component, const char *message, va_list args);
        virtual void log(LogEngine::levelType level, const char *component, const char *message, ...);

        private:
        int baudRate;
        Stream* serial;
    };

    Stream* usbCDCHelper(int baudRate);
};

#endif //lOGENGINE_SERIAL_H