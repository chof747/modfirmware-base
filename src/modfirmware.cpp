#include "modfirmware.h"
#include "modfw_component.h"
#include "controller.h"
#include "configstore.h"

using namespace ModFirmWare;

Application::Application(uint8_t numcomponents, const char* id) : 
numcomponents(numcomponents), appId(id)
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
    delete configStore;
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

void Application::startWith(Controller* controller)
//****************************************************************************************
{
    activeController = controller;
}

void Application::setup()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->setup();
    }
    configStore = ConfigStore::getInstance(this->appId);

    if (nullptr != activeController)
    {
        activeController->activate();
    }
}

void Application::loop()
//****************************************************************************************
{
    for (int i = 0; i < numcomponents; ++i)
    {
        components[i]->loop();
    }

    if (nullptr != activeController)
    {
        activeController->loop();
    }
}

void Application::onActivateController(Controller* active)
//****************************************************************************************
{
    activeController = active;
}