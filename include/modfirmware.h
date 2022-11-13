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
        Application(uint8_t numcomponents, const char *id);
        ~Application();

        uint8_t addComponent(Component *component);
        bool registerController(Controller *controller, Controller *next = NULL, Controller *alternateNext = NULL);
        void startWith(Controller *controller);

        inline uint8_t countComponents() { return numcomponents; }
        Component* operator[](uint8_t ix); 

        void triggerConfigMode();

        void setup();
        void loop();

    private:
        uint8_t numcomponents;
        const char *appId;
        Component **components;
        Controller *activeController;

        bool inConfigMode;

        void onActivateController(Controller *active);
    };
};

#endif // MODFIRMWARE_HH