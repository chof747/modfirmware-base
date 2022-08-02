#include "modfirmware.h"
#include "component.h"
#include "controller.h"

using namespace ModFirmWare;

Application::Application(uint8_t numcomponents) : numcomponents(numcomponents)
//****************************************************************************************
{
    components = new Component *[numcomponents];
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i] = NULL;
    }
}

Application::~Application()
//****************************************************************************************
{
    delete components;
}

uint8_t Application::addComponent(Component *component)
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

bool Application::registerController(Controller *controller, Controller *next, Controller *alternateNext)
//****************************************************************************************
{
    activation_cb_t cb = std::bind(&Application::onActivateController,
                                   this,
                                   std::placeholders::_1);

    controller->setActivationCallback(cb);
    controller->setNext(next);
    controller->setAlternateNext(alternateNext);

    return true;
}

void Application::setup()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->setup();
    }
}

void Application::loop()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->loop();
    }
}

void Application::onActivateController(Controller* active)
//****************************************************************************************
{
    activeController = active;
}