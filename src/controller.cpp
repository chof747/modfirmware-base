#include "controller.h"
#include "logengine.h"

using namespace ModFirmWare;

// Controller Implementation
Controller::Controller()
    //****************************************************************************************
    : prev(nullptr),
      alternatePrev(nullptr),
      activationCallBack(nullptr),
      active(false),
      logger(LogEngine::getInstance())
{
}

void Controller::activate()
//****************************************************************************************
{
    if (activationCallBack)
    {
        activationCallBack(this);
    }
    active = true;
}

void Controller::deactivate()
//****************************************************************************************
{
    active = false;
}

void Controller::setActivationCallback(ActivationCallback cb)
//****************************************************************************************
{
    activationCallBack = cb;
}

void Controller::setPrev(Controller *c)
//****************************************************************************************
{
    prev = c;
}

void Controller::setAlternatePrev(Controller *c)
//****************************************************************************************
{
    alternatePrev = c;
}

void Controller::gotoPrev()
//****************************************************************************************
{
    gotoController(prev);
}

void Controller::gotoAlternatePrev()
//****************************************************************************************
{
    gotoController(alternatePrev);
}

void Controller::gotoController(Controller *controller)
//****************************************************************************************
{
    if (NULL != controller)
    {
        controller->activate();
    }
}
