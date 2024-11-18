import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]

CONF_UART = "uart"
CONF_BRC_PIN = "brc_pin"
CONF_LAZY_650 = "lazy_650"
CONF_ROOMBA_ID = "roomba_id"

roomba_ns = cg.esphome_ns.namespace("roomba")
RoombaComponent = roomba_ns.class_("RoombaComponent", cg.PollingComponent)
RoombaClient = roomba_ns.class_("RoombaClient")
uart_ns = cg.esphome_ns.namespace("uart")
UARTComponent = uart_ns.class_("UARTComponent")

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RoombaComponent),
        cv.Required(CONF_UART): cv.use_id(UARTComponent),
        cv.Required(CONF_BRC_PIN): cv.int_,
        cv.Required(CONF_LAZY_650): cv.boolean,
    }
).extend(cv.polling_component_schema("10s"))

ROOMBA_CLIENT_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_ROOMBA_ID): cv.use_id(RoombaComponent),
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    brc_pin = await cg.get_variable(config[CONF_BRC_PIN])
    uart = await cg.get_variable(config[CONF_UART])
    lazy_650 = await cg.get_variable(config[CONF_LAZY_650])
    cg.add(var.set_brc_pin(brc_pin))
    cg.add(var.set_uart(uart))
    cg.add(var.set_lazy_650(lazy_650))
