#include "modfirmware.h"
#include "modfw_component.h"
#include "controller.h"

using namespace ModFirmWare;

Application::Application(const char* id) : 
components(), appId(id), inConfigMode(false)
//****************************************************************************************
{
}

Application::~Application()
//****************************************************************************************
{
    components.clear();
}

size_t Application::addComponent(Component *component)
//****************************************************************************************
{
    components.push_back(component);
    return components.size();
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

Component* Application::operator[](size_t ix)
//****************************************************************************************
{
    if (ix < components.size())
    {
        return components[ix];
    }
    else
    {
        return nullptr;
    }
}

void Application::triggerConfigMode()
//****************************************************************************************
{
    inConfigMode = true;
}

void Application::setup()
//****************************************************************************************
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        components[i]->setup(this);
    }

    for (size_t i = 0; i < components.size(); ++i)
    {
        components[i]->afterSetup();
    }

    if (nullptr != activeController)
    {
        activeController->activate();
    }
}

void Application::loop()
//****************************************************************************************
{
    for (size_t i = 0; i < components.size(); ++i)
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