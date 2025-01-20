#pragma once

#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"
#include "dht11.h"
#include "Arduino.h"

#define DHT11PIN D0

namespace esphome
{
  namespace empty_sensor
  {
    static const char *TAG = "empty_sensor";

    class EmptySensor : public sensor::Sensor, public PollingComponent
    {
      void setup() override;
      void loop() override;
      void update() override;
      void dump_config() override;

    private:
      dht11 my_dht_sensor;
    };

  } // namespace empty_sensor
} // namespace esphome