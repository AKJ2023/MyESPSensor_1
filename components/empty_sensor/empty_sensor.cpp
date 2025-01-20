#include "empty_sensor.h"
#include "esphome/core/log.h"

namespace esphome
{
    namespace empty_sensor
    {

        static const char *TAG = "empty_sensor.sensor";

        void EmptySensor::setup()
        {
            ESP_LOGV(TAG, "Hello World");
        }

        void EmptySensor::loop() {}

        void EmptySensor::update()
        {
            ESP_LOGV(TAG, "Updating");

            int chk = my_dht_sensor.read(DHT11PIN);
            publish_state(my_dht_sensor.temperature);
        }

        void EmptySensor::dump_config() { ESP_LOGCONFIG(TAG, "Empty custom sensor"); }

    } // namespace empty_sensor
} // namespace esphome