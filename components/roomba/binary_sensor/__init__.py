import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_RUNNING,
    ENTITY_CATEGORY_NONE,
)

from .. import (
    roomba_ns,
    CONF_ROOMBA_ID,
    ROOMBA_CLIENT_SCHEMA,
    RoombaClient,
)

RoombaBinarySensor = roomba_ns.class_(
    "RoombaBinarySensor", cg.PollingComponent, RoombaClient
)

CONF_VACUUM = "vacuum"
CONF_LEFT_WHEEL_DROP = "left_wheel_drop"
CONF_RIGHT_WHEEL_DROP = "right_wheel_drop"
CONF_LEFT_BUMPS = "left_bumps"
CONF_RIGHT_BUMPS = "right_bumps"
CONF_WALL = "wall"
CONF_LEFT_CLIFF = "left_cliff"
CONF_FRONT_LEFT_CLIFF = "front_left_cliff"
CONF_FRONT_RIGHT_CLIFF = "front_right_cliff"
CONF_RIGHT_CLIFF = "right_cliff"
CONF_VIRTUAL_WALL = "virtual_wall"
CONF_SIDE_BRUSH_OVERCURRENT = "side_brush_overcurrent"
CONF_MAIN_BRUSH_OVERCURRENT = "main_brush_overcurrent"
CONF_RIGHT_WHEEL_OVERCURRENT = "right_wheel_overcurrent"
CONF_LEFT_WHEEL_OVERCURRENT = "left_wheel_overcurrent"
CONF_CLEAN_BUTTON = "clean_button"
CONF_SPOT_BUTTON = "spot_button"
CONF_DOCK_BUTTON = "dock_button"
CONF_MINUTE_BUTTON = "minute_button"
CONF_HOUR_BUTTON = "hour_button"
CONF_DAY_BUTTON = "day_button"
CONF_SCHEDULE_BUTTON = "schedule_button"
CONF_CLOCK_BUTTON = "clock_button"
CONF_INTERNAL_CHARGER_CHARGING_SOURCE_AVAILABLE = (
    "internal_charger_charging_source_available"
)
CONF_HOME_BASE_CHARGING_SOURCE_AVAILABLE = "home_base_charging_source_available"
CONF_SONG_PLAYING = "song_playing"
CONF_LEFT_LIGHT_BUMPER = "left_light_bumper"
CONF_LEFT_FRONT_LIGHT_BUMPER = "left_front_light_bumper"
CONF_LEFT_CENTER_LIGHT_BUMPER = "left_center_light_bumper"
CONF_RIGHT_CENTER_LIGHT_BUMPER = "right_center_light_bumper"
CONF_RIGHT_FRONT_LIGHT_BUMPER = "right_front_light_bumper"
CONF_RIGHT_LIGHT_BUMPER = "right_light_bumper"
CONF_TOGGLING_STASIS = "toggling_stasis"
CONF_DISABLED_STASIS = "disabled_stasis"


CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(RoombaBinarySensor),
            cv.Optional(CONF_VACUUM): binary_sensor.binary_sensor_schema(
                icon="mdi:robot-vacuum",
                entity_category=ENTITY_CATEGORY_NONE,
                device_class=DEVICE_CLASS_RUNNING,
            ),
            cv.Optional(CONF_LEFT_WHEEL_DROP): binary_sensor.binary_sensor_schema(
                icon="mdi:wheelbarrow",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_RIGHT_WHEEL_DROP): binary_sensor.binary_sensor_schema(
                icon="mdi:wheelbarrow",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_LEFT_BUMPS): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_RIGHT_BUMPS): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_WALL): binary_sensor.binary_sensor_schema(
                icon="mdi:wall",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_LEFT_CLIFF): binary_sensor.binary_sensor_schema(
                icon="mdi:arrow-down-bold",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_FRONT_LEFT_CLIFF): binary_sensor.binary_sensor_schema(
                icon="mdi:arrow-down-bold",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_FRONT_RIGHT_CLIFF): binary_sensor.binary_sensor_schema(
                icon="mdi:arrow-down-bold",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_RIGHT_CLIFF): binary_sensor.binary_sensor_schema(
                icon="mdi:arrow-down-bold",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_VIRTUAL_WALL): binary_sensor.binary_sensor_schema(
                icon="mdi:wall",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_SIDE_BRUSH_OVERCURRENT
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_MAIN_BRUSH_OVERCURRENT
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_RIGHT_WHEEL_OVERCURRENT
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_LEFT_WHEEL_OVERCURRENT
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_CLEAN_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_SPOT_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_DOCK_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_MINUTE_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_HOUR_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_DAY_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_SCHEDULE_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_CLOCK_BUTTON): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_INTERNAL_CHARGER_CHARGING_SOURCE_AVAILABLE
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_HOME_BASE_CHARGING_SOURCE_AVAILABLE
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:power",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_SONG_PLAYING): binary_sensor.binary_sensor_schema(
                icon="mdi:music",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_LEFT_LIGHT_BUMPER): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_LEFT_FRONT_LIGHT_BUMPER
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_LEFT_CENTER_LIGHT_BUMPER
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_RIGHT_CENTER_LIGHT_BUMPER
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(
                CONF_RIGHT_FRONT_LIGHT_BUMPER
            ): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_RIGHT_LIGHT_BUMPER): binary_sensor.binary_sensor_schema(
                icon="mdi:car-brake-alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_TOGGLING_STASIS): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_DISABLED_STASIS): binary_sensor.binary_sensor_schema(
                icon="mdi:alert",
                entity_category=ENTITY_CATEGORY_NONE,
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

    if CONF_VACUUM in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_VACUUM])
        cg.add(var.set_vacuum_sensor(sens))

    if CONF_LEFT_WHEEL_DROP in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_LEFT_WHEEL_DROP])
        cg.add(var.set_left_wheel_drop_sensor(sens))

    if CONF_RIGHT_WHEEL_DROP in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_RIGHT_WHEEL_DROP])
        cg.add(var.set_right_wheel_drop_sensor(sens))

    if CONF_LEFT_BUMPS in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_LEFT_BUMPS])
        cg.add(var.set_left_bumps_sensor(sens))

    if CONF_RIGHT_BUMPS in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_RIGHT_BUMPS])
        cg.add(var.set_right_bumps_sensor(sens))

    if CONF_WALL in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_WALL])
        cg.add(var.set_wall_sensor(sens))

    if CONF_LEFT_CLIFF in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_LEFT_CLIFF])
        cg.add(var.set_left_cliff_sensor(sens))

    if CONF_FRONT_LEFT_CLIFF in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_FRONT_LEFT_CLIFF])
        cg.add(var.set_front_left_cliff_sensor(sens))

    if CONF_FRONT_RIGHT_CLIFF in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_FRONT_RIGHT_CLIFF])
        cg.add(var.set_front_right_cliff_sensor(sens))

    if CONF_RIGHT_CLIFF in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_RIGHT_CLIFF])
        cg.add(var.set_right_cliff_sensor(sens))

    if CONF_VIRTUAL_WALL in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_VIRTUAL_WALL])
        cg.add(var.set_virtual_wall_sensor(sens))

    if CONF_SIDE_BRUSH_OVERCURRENT in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_SIDE_BRUSH_OVERCURRENT]
        )
        cg.add(var.set_side_brush_overcurrent_sensor(sens))

    if CONF_MAIN_BRUSH_OVERCURRENT in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_MAIN_BRUSH_OVERCURRENT]
        )
        cg.add(var.set_main_brush_overcurrent_sensor(sens))

    if CONF_RIGHT_WHEEL_OVERCURRENT in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_RIGHT_WHEEL_OVERCURRENT]
        )
        cg.add(var.set_right_wheel_overcurrent_sensor(sens))

    if CONF_LEFT_WHEEL_OVERCURRENT in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_LEFT_WHEEL_OVERCURRENT]
        )
        cg.add(var.set_left_wheel_overcurrent_sensor(sens))

    if CONF_CLEAN_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_CLEAN_BUTTON])
        cg.add(var.set_clean_button_sensor(sens))

    if CONF_SPOT_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_SPOT_BUTTON])
        cg.add(var.set_spot_button_sensor(sens))

    if CONF_DOCK_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_DOCK_BUTTON])
        cg.add(var.set_dock_button_sensor(sens))

    if CONF_MINUTE_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_MINUTE_BUTTON])
        cg.add(var.set_minute_button_sensor(sens))

    if CONF_HOUR_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_HOUR_BUTTON])
        cg.add(var.set_hour_button_sensor(sens))

    if CONF_DAY_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_DAY_BUTTON])
        cg.add(var.set_day_button_sensor(sens))

    if CONF_SCHEDULE_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_SCHEDULE_BUTTON])
        cg.add(var.set_schedule_button_sensor(sens))

    if CONF_CLOCK_BUTTON in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_CLOCK_BUTTON])
        cg.add(var.set_clock_button_sensor(sens))

    if CONF_INTERNAL_CHARGER_CHARGING_SOURCE_AVAILABLE in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_INTERNAL_CHARGER_CHARGING_SOURCE_AVAILABLE]
        )
        cg.add(var.set_internal_charger_charging_source_available_sensor(sens))

    if CONF_HOME_BASE_CHARGING_SOURCE_AVAILABLE in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_HOME_BASE_CHARGING_SOURCE_AVAILABLE]
        )
        cg.add(var.set_home_base_charging_source_available_sensor(sens))

    if CONF_SONG_PLAYING in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_SONG_PLAYING])
        cg.add(var.set_song_playing_sensor(sens))

    if CONF_LEFT_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_LEFT_LIGHT_BUMPER])
        cg.add(var.set_left_light_bumper_sensor(sens))

    if CONF_LEFT_FRONT_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_LEFT_FRONT_LIGHT_BUMPER]
        )
        cg.add(var.set_left_front_light_bumper_sensor(sens))

    if CONF_LEFT_CENTER_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_LEFT_CENTER_LIGHT_BUMPER]
        )
        cg.add(var.set_left_center_light_bumper_sensor(sens))

    if CONF_RIGHT_CENTER_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_RIGHT_CENTER_LIGHT_BUMPER]
        )
        cg.add(var.set_right_center_light_bumper_sensor(sens))

    if CONF_RIGHT_FRONT_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(
            config[CONF_RIGHT_FRONT_LIGHT_BUMPER]
        )
        cg.add(var.set_right_front_light_bumper_sensor(sens))

    if CONF_RIGHT_LIGHT_BUMPER in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_RIGHT_LIGHT_BUMPER])
        cg.add(var.set_right_light_bumper_sensor(sens))

    if CONF_TOGGLING_STASIS in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_TOGGLING_STASIS])
        cg.add(var.set_toggling_stasis_sensor(sens))

    if CONF_DISABLED_STASIS in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_DISABLED_STASIS])
        cg.add(var.set_disabled_stasis_sensor(sens))
