#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

namespace ModFirmWare
{
    class Controller;
    typedef std::function<void(Controller *)> activation_cb_t;

    class Controller
    {
    public:
        Controller();

        virtual void activate() = 0;
        virtual void loop() = 0;
        virtual void deactivate() {}

        void setActivationCallback(activation_cb_t cb);
        void setNext(Controller *c);
        void setAlternateNext(Controller *c);

    protected:
        void gotoNext();
        void gotoAlternateNext();
        void gotoController(Controller *controller);

    private:
        Controller *next;
        Controller *alternateNext;
        activation_cb_t activationCallBack;
    };

};

#endif // CONTROLLER_H