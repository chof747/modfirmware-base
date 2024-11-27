#ifndef IDLEABLECONTROLLER_H
#define IDLEABLECONTROLLER_H

#include "controller.h"

#ifndef IN_SECONDS
#define IN_SECONDS *1000
#endif

#include "controller.h"

namespace ModFirmWare
{
    class IdleableController : public Controller
    {
    public:
        using IdleCallback = std::function<bool(Controller *)>;
        IdleableController(Controller* idleController);

        void loop() override;
        virtual void activate();
        void checkAndExecuteIdling();
        void setIdleCallback(IdleCallback cb);
        void setIdleController(Controller* idleController);
        void setIdlePeriod(unsigned long period);
        inline void watchdog() { lastActiveTimeStamp = millis(); } // Adding inline watchdog method

    protected:
        IdleCallback idleCallBack;
        unsigned long lastActiveTimeStamp;
        unsigned long idlePeriod;
        Controller *idleController;
    };
}

#endif // IDLEABLECONTROLLER_H