#ifndef SENSOR_COMPONENT_H
#define SENSOR_COMPONENT_H

#include <modfw_component.h>
#include <Arduino.h>

#ifndef IN_SECONDS
  #define IN_SECONDS *1000
#endif

namespace ModFirmWare
{
  class SensorComponent : public Component
  {
  public:
  using UpdateCallback = std::function<void(SensorComponent *)>;
    SensorComponent()
        : Component(), updateInterval(15 IN_SECONDS), lastUpdate(0) {}
    SensorComponent(time_t updateInterval)
        : Component(), updateInterval(updateInterval), lastUpdate(0) {}

    virtual void loop() override final;
    virtual bool measureContinuously() { return false; }
    virtual bool measure() = 0;

    void setUpdateInterval(time_t interval);
    inline const time_t getUpdateInterval() { return updateInterval; }

    void setUpdateCallback(UpdateCallback cb) { onUpdate = cb; }

  protected:
    time_t updateInterval;
    time_t lastUpdate;

    UpdateCallback onUpdate;
  };
};

#endif // SENSOR_COMPONENT_H