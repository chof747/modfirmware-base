#include "controller.h"

Controller::Controller(): 
  next(NULL), alternateNext(NULL) {}

void Controller::setNext(Controller* c)
//****************************************************************************************
{
    this->next = c;
}

void Controller::setActivationCallback(activation_cb_t cb)
//****************************************************************************************
{
    activationCallBack = cb;
}


void Controller::setAlternateNext(Controller* c)
//****************************************************************************************
{
    this->alternateNext = c;
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

void Controller::gotoController(Controller* controller)
//****************************************************************************************
{
    if (NULL != controller)
    {
        this->deactivate();
        controller->activate();
        activationCallBack(controller);
    }
}