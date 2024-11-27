#include "controller.h"
#include "logengine.h"

using namespace ModFirmWare;

// Controller Implementation
Controller::Controller()
    //****************************************************************************************
    : next(nullptr), alternateNext(nullptr), activationCallBack(nullptr), logger(LogEngine::getInstance())
{
}

void Controller::activate()
//****************************************************************************************
{
    if (activationCallBack)
    {
        activationCallBack(this);
    }
}

void Controller::setActivationCallback(ActivationCallback cb)
//****************************************************************************************
{
    activationCallBack = cb;
}

void Controller::setNext(Controller *c)
//****************************************************************************************
{
    next = c;
}

void Controller::setAlternateNext(Controller *c)
//****************************************************************************************
{
    alternateNext = c;
}

void Controller::gotoNext()
//****************************************************************************************
{
    gotoController(next);
}

void Controller::gotoAlternateNext()
//****************************************************************************************
{
    gotoController(alternateNext);
}

void Controller::gotoController(Controller *controller)
//****************************************************************************************
{
    if (NULL != controller)
    {
        this->deactivate();
        controller->activate();
        if (NULL != activationCallBack)
        {
            activationCallBack(controller);
        }
    }
}
