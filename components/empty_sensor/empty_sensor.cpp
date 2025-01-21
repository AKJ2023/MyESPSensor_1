#include "empty_sensor.h"
#include "esphome/core/log.h"

namespace esphome
{
    namespace empty_sensor
    {
        void EmptySensor::setup()
        {
            ESP_LOGI(MYTAG, "Hello World");
        }

        void EmptySensor::loop() {
            ESP_LOGI(MYTAG, "Looping");
            String line = readString();
            int i = parseInt();
            while (available()) {
            char c = read();
            }
        }

        void EmptySensor::update()
        {
            ESP_LOGI(MYTAG, "Updating");
        }

        void EmptySensor::dump_config() { ESP_LOGCONFIG(MYTAG, "Empty custom sensor"); }

    } // namespace empty_sensor
} // namespace esphome