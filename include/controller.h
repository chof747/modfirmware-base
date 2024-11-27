#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

namespace ModFirmWare
{
    class LogEngine;
    class Controller
    {
    public:
        using ActivationCallback = std::function<void(Controller *)>;
        Controller();

        virtual void activate();
        virtual void loop() = 0; // Making loop an abstract method
        virtual void deactivate() {}

        void setActivationCallback(ActivationCallback cb);
        void setNext(Controller *c);
        void setAlternateNext(Controller *c);

    protected:
        Controller *next;
        Controller *alternateNext;
        ActivationCallback activationCallBack;

        LogEngine *logger;


        void gotoNext();
        void gotoAlternateNext();

    private:
        void gotoController(Controller* controller);
    };
};

#endif // CONTROLLER_H