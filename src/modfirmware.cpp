#include "modfirmware.h"
#include "component.h"

ModFirmWareManager::ModFirmWareManager(uint8_t numcomponents): numcomponents(numcomponents)
{
    components = new Component*[numcomponents];
    for(int i=0;i<numcomponents;++i)
    {
        components[i] = NULL;
    }
}

ModFirmWareManager::~ModFirmWareManager()
{
    delete components;
}

uint8_t ModFirmWareManager::addComponent(Component* component)
{
    for(int i=0;i<numcomponents;++i)
    {
        if (NULL == components[i])
        {
            components[i] = component;
            return i;
        }
    }

    return numcomponents + 1;
}

void ModFirmWareManager::setup()
{
    for(int i=0;i<numcomponents;++i)
    {
        components[i]->setup();
    }    
}

void ModFirmWareManager::loop()
{
    for(int i=0;i<numcomponents;++i)
    {
        components[i]->loop();
    }    
}