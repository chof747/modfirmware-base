#include "sensor_component.h"

using namespace ModFirmWare;

#define LOGTAG "sensor"

bool initial = true;

void SensorComponent::loop()
//****************************************************************************************
{
  bool changed = measureContinuously();

  if ((millis() - lastUpdate) >= updateInterval)
  {
    time_t now = millis();
    changed |= measure();
    lastUpdate = now;
  }

  if (changed && (NULL != onUpdate))
  {
    onUpdate(this);
  }
}

void SensorComponent::measureNow()
//****************************************************************************************
{
  bool changed = measureContinuously();
  changed |= measure();
  
  if (changed && (NULL != onUpdate))
  {
    onUpdate(this);
  }
}
void SensorComponent::setUpdateInterval(time_t interval)
//****************************************************************************************
{
  if (0 < interval)
  {
    updateInterval = interval;
  }
}