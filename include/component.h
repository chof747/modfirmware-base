#ifndef COMPONENT_H
#define COMPONENT_H

#include "logengine.h"

namespace ModFirmWare
{

    class Component
    {

    public:
        virtual bool setup();
        virtual void afterSetup() {}
        virtual void loop() = 0;

        virtual bool powerOnTest() { return true; }

    protected:
        LogEngine *logger;
    };

};

#endif // COMPONENT_G