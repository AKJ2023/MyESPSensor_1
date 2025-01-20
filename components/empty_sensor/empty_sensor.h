#pragma once

#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"
#include "dht11/dht11.h"

static const uint8_t D0 = 3;
static const uint8_t D1 = 1;
static const uint8_t D2 = 16;
static const uint8_t D3 = 5;
static const uint8_t D4 = 4;
static const uint8_t D5 = 14;
static const uint8_t D6 = 12;
static const uint8_t D7 = 13;
static const uint8_t D8 = 0;
static const uint8_t D9 = 2;
static const uint8_t D10 = 15;
static const uint8_t D11 = 13;
static const uint8_t D12 = 12;
static const uint8_t D13 = 14;
static const uint8_t D14 = 4;
static const uint8_t D15 = 5;

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