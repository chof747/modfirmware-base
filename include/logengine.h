#ifndef LOGENGINE_H
#define LOGENGINE_H

#include <stdarg.h>

namespace ModFirmWare
{
    class LogEngineStrategy;

    class LogEngine
    {
    public:

        enum levelType
        {
            NONE = 0,
            ERROR = 1,
            WARN = 2,
            INFO = 3,
            DEBUG = 4
        };

        static LogEngine* getInstance(int numLoggers = 1);
        LogEngine(LogEngine &other) = delete;
        void operator=(const LogEngine &) = delete;

        int addStrategy(LogEngineStrategy* loggingStrategy);

        void info(const char *component, const char *message, ...)
        {
            va_list args;
            va_start(args, message);
            this->log(levelType::INFO, component, message, args);
            va_end(args);
        }
        void warn(const char *component, const char *message, ...)
        {
            va_list args;
            va_start(args, message);
            this->log(levelType::WARN, component, message, args);
            va_end(args);
        }
        void error(const char *component, const char *message, ...)
        {
            va_list args;
            va_start(args, message);
            this->log(levelType::ERROR, component, message, args);
            va_end(args);
        }
        void debug(const char *component, const char *message, ...)
        {
            va_list args;
            va_start(args, message);
            this->log(levelType::DEBUG, component, message, args);
            va_end(args);
        }

    protected:
        LogEngineStrategy** strategies;
        int numLoggers;
        void log(levelType level, const char *component, const char *message, va_list args);

    private:
        static LogEngine *_instance;

        LogEngine(int numLoggers);
    };

};
#endif // LOGENGINE_H