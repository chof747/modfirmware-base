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
    bool registerController(Controller* controller, Controller* next = NULL, Controller* alternateNext = NULL);

    void setup();
    void loop();

private:
    uint8_t numcomponents;
    Component **components;
    Controller* activeController;

    void onActivateController(Controller* active);
};

#endif // MODFIRMWARE_HH