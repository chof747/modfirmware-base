#ifndef MODFIRMWARE_HH
#define MODFIRMWARE_HH

#include <Arduino.h>

class Controller;
class Component;

class ModFirmWareManager
{
public:
    ModFirmWareManager(uint8_t numcomponents);
    ~ModFirmWareManager();

    uint8_t addComponent(Component* component);

    void setup();
    void loop();

private:
    uint8_t numcomponents;
    Component **components;
};

#endif // MODFIRMWARE_HH