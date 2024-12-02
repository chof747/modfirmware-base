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
        void setPrev(Controller *c);
        void setAlternatePrev(Controller *c);

    protected:
        Controller *prev;
        Controller *alternatePrev;
        ActivationCallback activationCallBack;

        LogEngine *logger;


        void gotoPrev();
        void gotoAlternatePrev();

    private:
        void gotoController(Controller* controller);
    };
};

#endif // CONTROLLER_H