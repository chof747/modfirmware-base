#include "modfirmware.h"
#include "component.h"
#include "controller.h"

ModFirmWareManager::ModFirmWareManager(uint8_t numcomponents) : numcomponents(numcomponents)
//****************************************************************************************
{
    components = new Component *[numcomponents];
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i] = NULL;
    }
}

ModFirmWareManager::~ModFirmWareManager()
//****************************************************************************************
{
    delete components;
}

uint8_t ModFirmWareManager::addComponent(Component *component)
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        if (NULL == components[i])
        {
            components[i] = component;
            return i;
        }
    }

    return numcomponents + 1;
}

bool ModFirmWareManager::registerController(Controller *controller, Controller *next, Controller *alternateNext)
//****************************************************************************************
{
    activation_cb_t cb = std::bind(&ModFirmWareManager::onActivateController,
                                   this,
                                   std::placeholders::_1);

    controller->setActivationCallback(cb);
    controller->setNext(next);
    controller->setAlternateNext(alternateNext);

    return true;
}

void ModFirmWareManager::setup()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->setup();
    }
}

void ModFirmWareManager::loop()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->loop();
    }
}

void ModFirmWareManager::onActivateController(Controller* active)
//****************************************************************************************
{
    activeController = active;
}