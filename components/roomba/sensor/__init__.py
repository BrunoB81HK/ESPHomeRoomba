import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_SPEED,
    DEVICE_CLASS_BATTERY,
    DEVICE_CLASS_CURRENT,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_TEMPERATURE,
    STATE_CLASS_MEASUREMENT,
)

from .. import (
    roomba_ns,
    CONF_ROOMBA_ID,
    ROOMBA_CLIENT_SCHEMA,
    RoombaClient,
)

RoombaSensor = roomba_ns.class_("RoombaSensor", cg.PollingComponent, RoombaClient)

CONF_VOLTAGE = "voltage"
CONF_CURRENT = "current"
CONF_BATTERY_CHARGE = "battery_charge"
CONF_BATTERY_CAPACITY = "battery_capacity"
CONF_BATTERY_PERCENT = "battery_percent"
CONF_BATTERY_TEMPERATURE = "battery_temperature"
CONF_DRIVE_SPEED = "drive_speed"
CONF_MAIN_BRUSH_CURRENT = "main_brush_current"
CONF_SIDE_BRUSH_CURRENT = "side_brush_current"

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(RoombaSensor),
            cv.Optional(CONF_VOLTAGE): sensor.sensor_schema(
                unit_of_measurement="V",
                icon="mdi:sine-wave",
                accuracy_decimals=2,
                device_class=DEVICE_CLASS_VOLTAGE,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CURRENT): sensor.sensor_schema(
                unit_of_measurement="A",
                icon="mdi:lightning-bolt",
                accuracy_decimals=3,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_CHARGE): sensor.sensor_schema(
                unit_of_measurement="Ah",
                icon="mdi:battery-charging",
                accuracy_decimals=2,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_CAPACITY): sensor.sensor_schema(
                unit_of_measurement="Ah",
                icon="mdi:battery",
                accuracy_decimals=2,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_PERCENT): sensor.sensor_schema(
                unit_of_measurement="%",
                icon="mdi:battery-outline",
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_BATTERY,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_TEMPERATURE): sensor.sensor_schema(
                unit_of_measurement="°C",
                icon="mdi:thermometer",
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_TEMPERATURE,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_DRIVE_SPEED): sensor.sensor_schema(
                unit_of_measurement="mm/s",
                icon="mdi:car-speed-limiter",
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_SPEED,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_MAIN_BRUSH_CURRENT): sensor.sensor_schema(
                unit_of_measurement="A",
                icon="mdi:lightning-bolt",
                accuracy_decimals=2,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_SIDE_BRUSH_CURRENT): sensor.sensor_schema(
                unit_of_measurement="A",
                icon="mdi:lightning-bolt",
                accuracy_decimals=2,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
        }
    )
    .extend(ROOMBA_CLIENT_SCHEMA)
    .extend(cv.polling_component_schema("10s"))
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    roomba_var = await cg.get_variable(config[CONF_ROOMBA_ID])
    cg.add(var.set_roomba(roomba_var))

    if CONF_VOLTAGE in config:
        sens = await sensor.new_sensor(config[CONF_VOLTAGE])
        cg.add(var.set_voltage_sensor(sens))

    if CONF_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_CURRENT])
        cg.add(var.set_current_sensor(sens))

    if CONF_BATTERY_CHARGE in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_CHARGE])
        cg.add(var.set_battery_charge_sensor(sens))

    if CONF_BATTERY_CAPACITY in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_CAPACITY])
        cg.add(var.set_battery_capacity_sensor(sens))

    if CONF_BATTERY_PERCENT in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_PERCENT])
        cg.add(var.set_battery_percent_sensor(sens))

    if CONF_BATTERY_TEMPERATURE in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_TEMPERATURE])
        cg.add(var.set_battery_temperature_sensor(sens))

    if CONF_DRIVE_SPEED in config:
        sens = await sensor.new_sensor(config[CONF_DRIVE_SPEED])
        cg.add(var.set_drive_speed_sensor(sens))

    if CONF_MAIN_BRUSH_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_MAIN_BRUSH_CURRENT])
        cg.add(var.set_main_brush_current_sensor(sens))

    if CONF_SIDE_BRUSH_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_SIDE_BRUSH_CURRENT])
        cg.add(var.set_side_brush_current_sensor(sens))
