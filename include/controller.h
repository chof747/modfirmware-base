#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

namespace ModFirmWare
{
    class Controller;

    class Controller
    {
    public:
        using ActivationCallback = std::function<void(Controller *)>;
        Controller();

        virtual void activate() = 0;
        virtual void loop() = 0;
        virtual void deactivate() {}

        void setActivationCallback(ActivationCallback cb);
        void setNext(Controller *c);
        void setAlternateNext(Controller *c);

    protected:
        void gotoNext();
        void gotoAlternateNext();
        void gotoController(Controller *controller);

    private:
        Controller *next;
        Controller *alternateNext;
        ActivationCallback activationCallBack;
    };

};

#endif // CONTROLLER_H