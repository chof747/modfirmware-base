#include "idleablecontroller.h"

using namespace ModFirmWare;

#ifndef CONTROLLER_IDLE_TIME
#define CONTROLLER_IDLE_TIME 20 IN_SECONDS
#endif

// IdleableController Implementation
IdleableController::IdleableController(Controller* idleController)
    : Controller(), idleCallBack(nullptr), lastActiveTimeStamp(0), 
    idlePeriod(CONTROLLER_IDLE_TIME), idleController(idleController)
//****************************************************************************************
{
}

void IdleableController::loop()
//****************************************************************************************
{
  checkAndExecuteIdling();
}

void IdleableController::activate()
//****************************************************************************************
{ 
  lastActiveTimeStamp = millis();
  Controller::activate();
}

void IdleableController::checkAndExecuteIdling()
//****************************************************************************************
{
    unsigned long currentTime = millis();
  if (currentTime - lastActiveTimeStamp > idlePeriod)
  {
    bool keepIdle = true;
    if (NULL != idleCallBack)
    {
      keepIdle = idleCallBack(this);
    }

    if (keepIdle && (NULL != idleController))
    {
      idleController->setPrev(this);
      idleController->activate();
    }
  }
}

void IdleableController::setIdleController(Controller * idleController)
//****************************************************************************************
{
  this->idleController = idleController;
}

void IdleableController::setIdleCallback(IdleCallback cb)
//****************************************************************************************
{
  idleCallBack = cb;
}

void IdleableController::setIdlePeriod(unsigned long period)
//****************************************************************************************
{
  idlePeriod = period;
}
