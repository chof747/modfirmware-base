#include "configstore.h"

#include <Preferences.h>

using namespace ModFirmWare;

Preferences preferences;

ConfigStore::ConfigStore(const char* prefNameSpace)
//****************************************************************************************
{
    preferences.begin(prefNameSpace, false);
}

ConfigStore* ConfigStore::set(const char* key, const char* value)
//****************************************************************************************
{
    return set(key, String(value));
}

ConfigStore* ConfigStore::set(const char* key, const String value)
//****************************************************************************************
{
    preferences.putString(key, value);
    return this;
}

ConfigStore* ConfigStore::set(const char* key, bool flag)
//****************************************************************************************
{
    preferences.putBool(key, flag);
    return this;
}

ConfigStore* ConfigStore::set(const char* key, int discrete)
//****************************************************************************************
{
    preferences.putInt(key, discrete);
    return this;
}

ConfigStore* ConfigStore::set(const char* key, float number)
//****************************************************************************************
{
    preferences.putFloat(key, number);
    return this;
}

ConfigStore* ConfigStore::set(const char* key, double precision)
//****************************************************************************************
{
    preferences.putDouble(key, precision);
    return this;
}

const String ConfigStore::getString(const char* key, String def)
//****************************************************************************************
{  
    return preferences.getString(key, def);
}
bool ConfigStore::getFlag(const char* key, bool def)
//****************************************************************************************
{
    return preferences.getBool(key, def);
}

int ConfigStore::getDiscrete(const char* key, int def)
//****************************************************************************************
{
    return preferences.getInt(key, def);
}

float ConfigStore::getNumber(const char* key, float def)
//****************************************************************************************
{
    return preferences.getFloat(key, def);
}

double getPrecision(const char* key, double def)
//****************************************************************************************
{
    return preferences.getDouble(key, def);
}

ConfigStore* ConfigStore::removeKey(const char* key)
//****************************************************************************************
{
    preferences.remove(key);
    return this;
}