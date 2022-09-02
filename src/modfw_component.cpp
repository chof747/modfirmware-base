#include "modfw_component.h"
#include "modfirmware.h"

using namespace ModFirmWare;

bool Component::setup(Application* app)
//******************************************************************************
{
    logger = LogEngine::getInstance();
    return true;
}