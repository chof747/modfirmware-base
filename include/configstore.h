#ifndef CONFIGSTORE_H
#define CONFIGSTORE_H

#include <Arduino.h>

namespace ModFirmWare
{   
    class ConfigStore 
    {
        public:

        ConfigStore(const char* prefNameSpace);
        ConfigStore* set(const char* key, const char* value);
        ConfigStore* set(const char* key, const String value);
        ConfigStore* set(const char* key, bool flag);
        ConfigStore* set(const char* key, int discrete);
        ConfigStore* set(const char* key, float number);
        ConfigStore* set(const char* key, double precision);

        const String getString(const char* key, String def = String());
        bool getFlag(const char* key, bool def = false);
        int getDiscrete(const char* key, int def = 0);
        float getNumber(const char* key, float def = 0.0);
        double getPrecision(const char* key, double def = 0.0);

        ConfigStore* removeKey(const char* key);
    };
};

#endif //CONFIGSTORE_H