import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, UNIT_CELSIUS, ICON_THERMOMETER, DEVICE_CLASS_TEMPERATURE

# Define namespace
sensor1_ns = cg.esphome_ns.namespace("sensor1")
Sensor1Component = sensor1_ns.class_("Sensor1Component", cg.PollingComponent)

# Schema for the component
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(Sensor1Component),
    cv.Optional("temperature"): sensor.sensor_schema(
        UNIT_CELSIUS,
        ICON_THERMOMETER,
        1,  # Accuracy decimals
        DEVICE_CLASS_TEMPERATURE,
    ),
})

def to_code(config):
    # Create a new instance of Sensor1Component
    var = cg.new_Pvariable(config[CONF_ID])
    if "temperature" in config:
        sens = yield sensor.new_sensor(config["temperature"])
        cg.add(var.set_temperature_sensor(sens))  # Add temperature sensor to the component
    yield cg.register_component(var, config)