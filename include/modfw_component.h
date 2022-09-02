#ifndef COMPONENT_H
#define COMPONENT_H

#include "logengine.h"

namespace ModFirmWare
{
    class Application;

    class Component
    {

    public:
        virtual bool setup(Application*);
        virtual void afterSetup() {}
        virtual void loop() = 0;

        virtual bool powerOnTest() { return true; }

    protected:
        LogEngine *logger;
    };

};

#endif // COMPONENT_H