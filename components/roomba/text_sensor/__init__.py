import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import (
    CONF_ID,
    ENTITY_CATEGORY_NONE,
)

from .. import (
    roomba_ns,
    CONF_ROOMBA_ID,
    ROOMBA_CLIENT_SCHEMA,
    RoombaClient,
)

RoombaTextSensor = roomba_ns.class_(
    "RoombaTextSensor", cg.PollingComponent, RoombaClient
)

CONF_ACTIVITY = "activity"
CONF_CHARGING = "charging_state"
CONF_OI_MODE = "oi_mode"

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(RoombaTextSensor),
            cv.Optional(CONF_ACTIVITY): text_sensor.text_sensor_schema(
                icon="mdi:briefcase",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_CHARGING): text_sensor.text_sensor_schema(
                icon="mdi:battery-charging-medium",
                entity_category=ENTITY_CATEGORY_NONE,
            ),
            cv.Optional(CONF_OI_MODE): text_sensor.text_sensor_schema(
                icon="mdi:auto-mode",
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

    if CONF_ACTIVITY in config:
        sens = await text_sensor.new_text_sensor(config[CONF_ACTIVITY])
        cg.add(var.set_activity_sensor(sens))

    if CONF_CHARGING in config:
        sens = await text_sensor.new_text_sensor(config[CONF_CHARGING])
        cg.add(var.set_charging_state_sensor(sens))

    if CONF_OI_MODE in config:
        sens = await text_sensor.new_text_sensor(config[CONF_OI_MODE])
        cg.add(var.set_oi_mode_sensor(sens))
