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

CONF_DIRT_DETECT = "dirt_detect"
CONF_IR_BYTE_OMNI = "ir_byte_omni"
CONF_IR_BYTE_LEFT = "ir_byte_left"
CONF_IR_BYTE_RIGHT = "ir_byte_right"
CONF_DISTANCE = "distance"
CONF_ANGLE = "angle"
CONF_VOLTAGE = "voltage"
CONF_CURRENT = "current"
CONF_BATTERY_TEMPERATURE = "battery_temperature"
CONF_BATTERY_CHARGE = "battery_charge"
CONF_BATTERY_CAPACITY = "battery_capacity"
CONF_BATTERY_PERCENT = "battery_percent"
CONF_WALL_SIGNAL = "wall_signal"
CONF_CLIFF_LEFT_SIGNAL = "cliff_left_signal"
CONF_CLIFF_FRONT_LEFT_SIGNAL = "cliff_front_left_signal"
CONF_CLIFF_FRONT_RIGHT_SIGNAL = "cliff_front_right_signal"
CONF_CLIFF_RIGHT_SIGNAL = "cliff_right_signal"
CONF_SONG_NUMBER = "song_number"
CONF_NUMBER_OF_STREAM_PACKETS = "number_of_stream_packets"
CONF_REQUESTED_VELOCITY = "requested_velocity"
CONF_REQUESTED_RADIUS = "requested_radius"
CONF_REQUESTED_RIGHT_VELOCITY = "requested_right_velocity"
CONF_REQUESTED_LEFT_VELOCITY = "requested_left_velocity"
CONF_LEFT_ENCODER_COUNTS = "left_encoder_counts"
CONF_RIGHT_ENCODER_COUNTS = "right_encoder_counts"
CONF_LIGHT_BUMP_LEFT_SIGNAL = "light_bump_left_signal"
CONF_LIGHT_BUMP_FRONT_LEFT_SIGNAL = "light_bump_front_left_signal"
CONF_LIGHT_BUMP_CENTER_LEFT_SIGNAL = "light_bump_center_left_signal"
CONF_LIGHT_BUMP_CENTER_RIGHT_SIGNAL = "light_bump_center_right_signal"
CONF_LIGHT_BUMP_FRONT_RIGHT_SIGNAL = "light_bump_front_right_signal"
CONF_LIGHT_BUMP_RIGHT_SIGNAL = "light_bump_right_signal"
CONF_LEFT_MOTOR_CURRENT = "left_motor_current"
CONF_RIGHT_MOTOR_CURRENT = "right_motor_current"
CONF_MAIN_BRUSH_CURRENT = "main_brush_current"
CONF_SIDE_BRUSH_CURRENT = "side_brush_current"

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(RoombaSensor),
            cv.Optional(CONF_DIRT_DETECT): sensor.sensor_schema(
                "%",
                "mdi:cloud",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_IR_BYTE_OMNI): sensor.sensor_schema(
                "",
                "mdi:remote",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_IR_BYTE_LEFT): sensor.sensor_schema(
                "",
                "mdi:remote",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_IR_BYTE_RIGHT): sensor.sensor_schema(
                "",
                "mdi:remote",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_DISTANCE): sensor.sensor_schema(
                "mm",
                "mdi:ruler",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_ANGLE): sensor.sensor_schema(
                "°",
                "mdi:angle-acute",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_VOLTAGE): sensor.sensor_schema(
                "mV",
                "mdi:flash",
                DEVICE_CLASS_VOLTAGE,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CURRENT): sensor.sensor_schema(
                "mA",
                "mdi:current-ac",
                DEVICE_CLASS_CURRENT,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_TEMPERATURE): sensor.sensor_schema(
                "°C",
                "mdi:thermometer",
                DEVICE_CLASS_TEMPERATURE,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_CHARGE): sensor.sensor_schema(
                "mAh",
                "mdi:battery-charging",
                DEVICE_CLASS_BATTERY,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_CAPACITY): sensor.sensor_schema(
                "mAh",
                "mdi:battery",
                DEVICE_CLASS_BATTERY,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BATTERY_PERCENT): sensor.sensor_schema(
                "%",
                "mdi:battery",
                DEVICE_CLASS_BATTERY,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_WALL_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:wall",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CLIFF_LEFT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:signal",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CLIFF_FRONT_LEFT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:signal",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CLIFF_FRONT_RIGHT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:signal",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_CLIFF_RIGHT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:signal",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_SONG_NUMBER): sensor.sensor_schema(
                "",
                "mdi:music-note",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_NUMBER_OF_STREAM_PACKETS): sensor.sensor_schema(
                "",
                "mdi:package-variant",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_REQUESTED_VELOCITY): sensor.sensor_schema(
                "mm/s",
                "mdi:speedometer",
                DEVICE_CLASS_SPEED,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_REQUESTED_RADIUS): sensor.sensor_schema(
                "mm",
                "mdi:ruler",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_REQUESTED_RIGHT_VELOCITY): sensor.sensor_schema(
                "mm/s",
                "mdi:speedometer",
                DEVICE_CLASS_SPEED,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_REQUESTED_LEFT_VELOCITY): sensor.sensor_schema(
                "mm/s",
                "mdi:speedometer",
                DEVICE_CLASS_SPEED,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LEFT_ENCODER_COUNTS): sensor.sensor_schema(
                "counts",
                "mdi:counter",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_RIGHT_ENCODER_COUNTS): sensor.sensor_schema(
                "counts",
                "mdi:counter",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_LEFT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_FRONT_LEFT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_CENTER_LEFT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_CENTER_RIGHT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_FRONT_RIGHT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LIGHT_BUMP_RIGHT_SIGNAL): sensor.sensor_schema(
                "",
                "mdi:lightbulb-on",
                None,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_LEFT_MOTOR_CURRENT): sensor.sensor_schema(
                "mA",
                "mdi:current-ac",
                DEVICE_CLASS_CURRENT,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_RIGHT_MOTOR_CURRENT): sensor.sensor_schema(
                "mA",
                "mdi:current-ac",
                DEVICE_CLASS_CURRENT,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_MAIN_BRUSH_CURRENT): sensor.sensor_schema(
                "mA",
                "mdi:current-ac",
                DEVICE_CLASS_CURRENT,
                STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_SIDE_BRUSH_CURRENT): sensor.sensor_schema(
                "mA",
                "mdi:current-ac",
                DEVICE_CLASS_CURRENT,
                STATE_CLASS_MEASUREMENT,
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

    if CONF_DIRT_DETECT in config:
        sens = await sensor.new_sensor(config[CONF_DIRT_DETECT])
        cg.add(var.set_dirt_detect_sensor(sens))

    if CONF_IR_BYTE_OMNI in config:
        sens = await sensor.new_sensor(config[CONF_IR_BYTE_OMNI])
        cg.add(var.set_ir_byte_omni_sensor(sens))

    if CONF_IR_BYTE_LEFT in config:
        sens = await sensor.new_sensor(config[CONF_IR_BYTE_LEFT])
        cg.add(var.set_ir_byte_left_sensor(sens))

    if CONF_IR_BYTE_RIGHT in config:
        sens = await sensor.new_sensor(config[CONF_IR_BYTE_RIGHT])
        cg.add(var.set_ir_byte_right_sensor(sens))

    if CONF_DISTANCE in config:
        sens = await sensor.new_sensor(config[CONF_DISTANCE])
        cg.add(var.set_distance_sensor(sens))

    if CONF_ANGLE in config:
        sens = await sensor.new_sensor(config[CONF_ANGLE])
        cg.add(var.set_angle_sensor(sens))

    if CONF_VOLTAGE in config:
        sens = await sensor.new_sensor(config[CONF_VOLTAGE])
        cg.add(var.set_voltage_sensor(sens))

    if CONF_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_CURRENT])
        cg.add(var.set_current_sensor(sens))

    if CONF_BATTERY_TEMPERATURE in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_TEMPERATURE])
        cg.add(var.set_battery_temperature_sensor(sens))

    if CONF_BATTERY_CHARGE in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_CHARGE])
        cg.add(var.set_battery_charge_sensor(sens))

    if CONF_BATTERY_CAPACITY in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_CAPACITY])
        cg.add(var.set_battery_capacity_sensor(sens))

    if CONF_BATTERY_PERCENT in config:
        sens = await sensor.new_sensor(config[CONF_BATTERY_PERCENT])
        cg.add(var.set_battery_percent_sensor(sens))

    if CONF_WALL_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_WALL_SIGNAL])
        cg.add(var.set_wall_signal_sensor(sens))

    if CONF_CLIFF_LEFT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_CLIFF_LEFT_SIGNAL])
        cg.add(var.set_cliff_left_signal_sensor(sens))

    if CONF_CLIFF_FRONT_LEFT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_CLIFF_FRONT_LEFT_SIGNAL])
        cg.add(var.set_cliff_front_left_signal_sensor(sens))

    if CONF_CLIFF_FRONT_RIGHT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_CLIFF_FRONT_RIGHT_SIGNAL])
        cg.add(var.set_cliff_front_right_signal_sensor(sens))

    if CONF_CLIFF_RIGHT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_CLIFF_RIGHT_SIGNAL])
        cg.add(var.set_cliff_right_signal_sensor(sens))

    if CONF_SONG_NUMBER in config:
        sens = await sensor.new_sensor(config[CONF_SONG_NUMBER])
        cg.add(var.set_song_number_sensor(sens))

    if CONF_NUMBER_OF_STREAM_PACKETS in config:
        sens = await sensor.new_sensor(config[CONF_NUMBER_OF_STREAM_PACKETS])
        cg.add(var.set_number_of_stream_packets_sensor(sens))

    if CONF_REQUESTED_VELOCITY in config:
        sens = await sensor.new_sensor(config[CONF_REQUESTED_VELOCITY])
        cg.add(var.set_requested_velocity_sensor(sens))

    if CONF_REQUESTED_RADIUS in config:
        sens = await sensor.new_sensor(config[CONF_REQUESTED_RADIUS])
        cg.add(var.set_requested_radius_sensor(sens))

    if CONF_REQUESTED_RIGHT_VELOCITY in config:
        sens = await sensor.new_sensor(config[CONF_REQUESTED_RIGHT_VELOCITY])
        cg.add(var.set_requested_right_velocity_sensor(sens))

    if CONF_REQUESTED_LEFT_VELOCITY in config:
        sens = await sensor.new_sensor(config[CONF_REQUESTED_LEFT_VELOCITY])
        cg.add(var.set_requested_left_velocity_sensor(sens))

    if CONF_LEFT_ENCODER_COUNTS in config:
        sens = await sensor.new_sensor(config[CONF_LEFT_ENCODER_COUNTS])
        cg.add(var.set_left_encoder_counts_sensor(sens))

    if CONF_RIGHT_ENCODER_COUNTS in config:
        sens = await sensor.new_sensor(config[CONF_RIGHT_ENCODER_COUNTS])
        cg.add(var.set_right_encoder_counts_sensor(sens))

    if CONF_LIGHT_BUMP_LEFT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_LEFT_SIGNAL])
        cg.add(var.set_light_bump_left_signal_sensor(sens))

    if CONF_LIGHT_BUMP_FRONT_LEFT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_FRONT_LEFT_SIGNAL])
        cg.add(var.set_light_bump_front_left_signal_sensor(sens))

    if CONF_LIGHT_BUMP_CENTER_LEFT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_CENTER_LEFT_SIGNAL])
        cg.add(var.set_light_bump_center_left_signal_sensor(sens))

    if CONF_LIGHT_BUMP_CENTER_RIGHT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_CENTER_RIGHT_SIGNAL])
        cg.add(var.set_light_bump_center_right_signal_sensor(sens))

    if CONF_LIGHT_BUMP_FRONT_RIGHT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_FRONT_RIGHT_SIGNAL])
        cg.add(var.set_light_bump_front_right_signal_sensor(sens))

    if CONF_LIGHT_BUMP_RIGHT_SIGNAL in config:
        sens = await sensor.new_sensor(config[CONF_LIGHT_BUMP_RIGHT_SIGNAL])
        cg.add(var.set_light_bump_right_signal_sensor(sens))

    if CONF_LEFT_MOTOR_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_LEFT_MOTOR_CURRENT])
        cg.add(var.set_left_motor_current_sensor(sens))

    if CONF_RIGHT_MOTOR_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_RIGHT_MOTOR_CURRENT])
        cg.add(var.set_right_motor_current_sensor(sens))

    if CONF_MAIN_BRUSH_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_MAIN_BRUSH_CURRENT])
        cg.add(var.set_main_brush_current_sensor(sens))

    if CONF_SIDE_BRUSH_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_SIDE_BRUSH_CURRENT])
        cg.add(var.set_side_brush_current_sensor(sens))
