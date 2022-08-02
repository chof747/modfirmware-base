#ifndef MODFIRMWARE_HH
#define MODFIRMWARE_HH

#include <Arduino.h>

namespace ModFirmWare
{

    class Controller;
    class Component;

    class Application
    {
    public:
        Application(uint8_t numcomponents);
        ~Application();

        uint8_t addComponent(Component *component);
        bool registerController(Controller *controller, Controller *next = NULL, Controller *alternateNext = NULL);

        void setup();
        void loop();

    private:
        uint8_t numcomponents;
        Component **components;
        Controller *activeController;

        void onActivateController(Controller *active);
    };
};
#endif // MODFIRMWARE_HH