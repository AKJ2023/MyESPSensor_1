#pragma once

#include "esphome.h"
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome
{
    namespace sensor1
    {

        static const char *TAG = "sensor1";

        class Sensor1Component : public PollingComponent
        {
        public:
            ComfoAirComponent() : PollingComponent(1000){

            }

            void setup() override {
                ESP_LOGV(TAG, "Hello World");
            }
            
            void update() override{
                ESP_LOGV(TAG, "Updating");
            }

            void loop() override{
                ESP_LOGV(TAG, "Looping");
            }

        protected:
        
        public:
            
        };

    } // namespace comfoair
} // namespace esphome