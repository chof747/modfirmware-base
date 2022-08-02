#include "component.h"

using namespace ModFirmWare;

bool Component::setup()
//******************************************************************************
{
    logger = LogEngine::getInstance();
    return true;
}