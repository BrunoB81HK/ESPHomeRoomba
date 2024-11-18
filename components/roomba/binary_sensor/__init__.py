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

CONF_VACCUUM = "vacuum"

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(RoombaBinarySensor),
            cv.Optional(CONF_VACCUUM): binary_sensor.binary_sensor_schema(
                icon="mdi:robot-vacuum",
                entity_category=ENTITY_CATEGORY_NONE,
                device_class=DEVICE_CLASS_RUNNING,
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

    if CONF_VACCUUM in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_VACCUUM])
        cg.add(var.set_vacuum_sensor(sens))
