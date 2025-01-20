import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, UNIT_CELSIUS, ICON_THERMOMETER, DEVICE_CLASS_TEMPERATURE

DEPENDENCIES = []

# Define a new component namespace
my_sensor_ns = cg.esphome_ns.namespace("my_sensor")
MySensor = my_sensor_ns.class_("MySensor", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(MySensor),
    cv.Optional("temperature"): sensor.sensor_schema(
        UNIT_CELSIUS,
        ICON_THERMOMETER,
        1,  # Accuracy decimals
        DEVICE_CLASS_TEMPERATURE,
    ),
})

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    if "temperature" in config:
        sens = yield sensor.new_sensor(config["temperature"])
        cg.add(var.set_temperature_sensor(sens))
    yield cg.register_component(var, config)