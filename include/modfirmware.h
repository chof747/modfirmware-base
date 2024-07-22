#ifndef MODFIRMWARE_HH
#define MODFIRMWARE_HH

#include <Arduino.h>
#include <vector>

namespace ModFirmWare
{

    class Controller;
    class Component;

    class Application
    {
    public:
        Application(const char *id);
        ~Application();

        size_t addComponent(Component *component);
        bool registerController(Controller *controller, Controller *next = NULL, Controller *alternateNext = NULL);
        void startWith(Controller *controller);

        inline size_t countComponents() { return components.size(); }
        Component* operator[](size_t ix); 

        void triggerConfigMode();

        void setup();
        void loop();

    private:
        const char *appId;
        std::vector<Component*> components;
        Controller *activeController;

        bool inConfigMode;

        void onActivateController(Controller *active);
    };
};

#endif // MODFIRMWARE_HH