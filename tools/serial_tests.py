# /// script
# requires-python = ">=3.12"
# dependencies = [
#   "pyserial",
# ]
# ///
import argparse
import enum
import struct

import serial


class Command(enum.IntEnum):
    # Getting started
    Reset = 7
    Start = 128
    Stop = 173
    Baud = 129
    # Mode
    Safe = 131
    Full = 132
    # Cleaning
    Clean = 135
    Max = 136
    Spot = 134
    SeekDock = 143
    Power = 133
    Schedule = 167
    SetDayTime = 168
    # Actuator
    Drive = 137
    DriveDirect = 145
    DrivePWM = 146
    Motors = 138
    MotorsPWM = 144
    LEDs = 139
    LEDsScheduling = 162
    LEDsDigitRaw = 163
    LEDsDigitASCII = 164
    Buttons = 165
    Song = 140
    Play = 141
    # Input
    Sensors = 142
    QueryList = 149
    Stream = 148
    StreamPauseResume = 150
    Control = 130


class SensorPackets(enum.IntEnum):
    Group7to26 = 0  # Size: 26 packets
    Group7to16 = 1  # Size: 10 packets
    Group17to20 = 2  # Size: 6 packets
    Group21to26 = 3  # Size: 10 packets
    Group27to34 = 4  # Size: 14 packets
    Group35to42 = 5  # Size: 12 packets
    Group7to42 = 6  # Size: 52 packets
    Group7to58 = 100  # Size: 80 packets
    Group43to58 = 101  # Size: 28 packets
    Group46to52 = 106  # Size: 12 packets
    Group54to58 = 107  # Size: 9 packets
    BumpsAndWheelDrops = 7  # 1 byte(s), unsigned
    Wall = 8  # 1 byte(s), unsigned
    CliffLeft = 9  # 1 byte(s), unsigned
    CliffFrontLeft = 10  # 1 byte(s), unsigned
    CliffFrontRight = 11  # 1 byte(s), unsigned
    CliffRight = 12  # 1 byte(s), unsigned
    VirtualWall = 13  # 1 byte(s), unsigned
    WheelOvercurrents = 14  # 1 byte(s), unsigned
    DirtDetect = 15  # 1 byte(s), unsigned
    Unused1 = 16  # 1 byte(s)
    IRByteOmni = 17  # 1 byte(s), unsigned
    IRByteLeft = 52  # 1 byte(s), unsigned
    IRByteRight = 53  # 1 byte(s), unsigned
    Buttons = 18  # 1 byte(s), unsigned
    Distance = 19  # 2 byte(s), signed
    Angle = 20  # 2 byte(s), signed
    ChargingState = 21  # 1 byte(s), unsigned
    Voltage = 22  # 2 byte(s), unsigned, mV
    Current = 23  # 2 byte(s), signed, mA
    BatteryTemperature = 24  # 1 byte(s), signed, C
    BatteryCharge = 25  # 2 byte(s), unsigned, mAh
    BatteryCapacity = 26  # 2 byte(s), unsigned, mAh
    WallSignal = 27  # 2 byte(s), unsigned
    CliffLeftSignal = 28  # 2 byte(s), unsigned
    CliffFrontLeftSignal = 29  # 2 byte(s), unsigned
    CliffFrontRightSignal = 30  # 2 byte(s), unsigned
    CliffRightSignal = 31  # 2 byte(s), unsigned
    Unused2 = 32  # 3 byte(s)
    Unused3 = 33  # 3 byte(s)
    ChargingSourcesAvailable = 34  # 1 byte(s), unsigned
    OIMode = 35  # 1 byte(s), unsigned
    SongNumber = 36  # 1 byte(s), unsigned
    SongPlaying = 37  # 1 byte(s), unsigned
    NumberOfStreamPackets = 38  # 1 byte(s), unsigned
    RequestedVelocity = 39  # 2 byte(s), signed, mm/s
    RequestedRadius = 40  # 2 byte(s), signed, mm
    RequestedRightVelocity = 41  # 2 byte(s), signed, mm/s
    RequestedLeftVelocity = 42  # 2 byte(s), signed, mm/s
    LeftEncoderCounts = 43  # 2 byte(s), signed, x*(pi*72.0/508.8) = distance in mm
    RightEncoderCounts = 44  # 2 byte(s), signed, x*(pi*72.0/508.8) = distance in mm
    LightBumper = 45  # 1 byte(s), unsigned
    LightBumpLeftSignal = 46  # 2 byte(s), unsigned
    LightBumpFrontLeftSignal = 47  # 2 byte(s), unsigned
    LightBumpCenterLeftSignal = 48  # 2 byte(s), unsigned
    LightBumpCenterRightSignal = 49  # 2 byte(s), unsigned
    LightBumpFrontRightSignal = 50  # 2 byte(s), unsigned
    LightBumpRightSignal = 51  # 2 byte(s), unsigned
    LeftMotorCurrent = 54  # 2 byte(s), signed, mA
    RightMotorCurrent = 55  # 2 byte(s), signed, mA
    MainBrushCurrent = 56  # 2 byte(s), signed, mA
    SideBrushCurrent = 57  # 2 byte(s), signed, mA
    Stasis = 58  # 2 byte(s), signed, mA


class RoombaSerial:
    SNSR_PCKT_META = {
        SensorPackets.BumpsAndWheelDrops: (1, "B"),
        SensorPackets.Wall: (1, "B"),
        SensorPackets.CliffLeft: (1, "B"),
        SensorPackets.CliffFrontLeft: (1, "B"),
        SensorPackets.CliffFrontRight: (1, "B"),
        SensorPackets.CliffRight: (1, "B"),
        SensorPackets.VirtualWall: (1, "B"),
        SensorPackets.WheelOvercurrents: (1, "B"),
        SensorPackets.DirtDetect: (1, "B"),
        SensorPackets.Unused1: (1, "B"),
        SensorPackets.IRByteOmni: (1, "B"),
        SensorPackets.Buttons: (1, "B"),
        SensorPackets.Distance: (2, "h"),
        SensorPackets.Angle: (2, "h"),
        SensorPackets.ChargingState: (1, "B"),
        SensorPackets.Voltage: (2, "H"),
        SensorPackets.Current: (2, "h"),
        SensorPackets.BatteryTemperature: (1, "b"),
        SensorPackets.BatteryCharge: (2, "H"),
        SensorPackets.BatteryCapacity: (2, "H"),
        SensorPackets.WallSignal: (2, "H"),
        SensorPackets.CliffLeftSignal: (2, "H"),
        SensorPackets.CliffFrontLeftSignal: (2, "H"),
        SensorPackets.CliffFrontRightSignal: (2, "H"),
        SensorPackets.CliffRightSignal: (2, "H"),
        SensorPackets.Unused2: (1, "B"),
        SensorPackets.Unused3: (2, "H"),
        SensorPackets.ChargingSourcesAvailable: (1, "B"),
        SensorPackets.OIMode: (1, "B"),
        SensorPackets.SongNumber: (1, "B"),
        SensorPackets.SongPlaying: (1, "B"),
        SensorPackets.NumberOfStreamPackets: (1, "B"),
        SensorPackets.RequestedVelocity: (2, "h"),
        SensorPackets.RequestedRadius: (2, "h"),
        SensorPackets.RequestedRightVelocity: (2, "h"),
        SensorPackets.RequestedLeftVelocity: (2, "h"),
        SensorPackets.LeftEncoderCounts: (2, "h"),
        SensorPackets.RightEncoderCounts: (2, "h"),
        SensorPackets.LightBumper: (1, "B"),
        SensorPackets.LightBumpLeftSignal: (2, "H"),
        SensorPackets.LightBumpFrontLeftSignal: (2, "H"),
        SensorPackets.LightBumpCenterLeftSignal: (2, "H"),
        SensorPackets.LightBumpCenterRightSignal: (2, "H"),
        SensorPackets.LightBumpFrontRightSignal: (2, "H"),
        SensorPackets.LightBumpRightSignal: (2, "H"),
        SensorPackets.IRByteLeft: (1, "B"),
        SensorPackets.IRByteRight: (1, "B"),
        SensorPackets.LeftMotorCurrent: (2, "h"),
        SensorPackets.RightMotorCurrent: (2, "h"),
        SensorPackets.MainBrushCurrent: (2, "h"),
        SensorPackets.SideBrushCurrent: (2, "h"),
        SensorPackets.Stasis: (1, "B"),
    }

    SNSR_PCKT_GROUP_META = {
        SensorPackets.Group7to26: (7, 26),
        SensorPackets.Group7to16: (7, 16),
        SensorPackets.Group17to20: (17, 20),
        SensorPackets.Group21to26: (21, 26),
        SensorPackets.Group27to34: (27, 34),
        SensorPackets.Group35to42: (35, 42),
        SensorPackets.Group7to42: (7, 42),
        SensorPackets.Group7to58: (7, 58),
        SensorPackets.Group43to58: (43, 58),
        SensorPackets.Group46to52: (46, 52),
        SensorPackets.Group54to58: (54, 58),
    }

    def __init__(
        self, port: str = "/dev/ttyUSB0", baudrate: int = 115200, timeout: float = 0.1
    ) -> None:
        self.serial = serial.Serial(port, baudrate, timeout=timeout)

    def __enter__(self):
        self.start()
        return self

    def __exit__(self, type, value, traceback):
        self.stop()

    def flush(self) -> None:
        self.serial.flush()

    def send(self, data) -> None:
        self.serial.write(struct.pack("B", data))

    def read_all(self, max: int = 100) -> bytes:
        return self.serial.read(max)

    def send_command(self, command: Command) -> None:
        self.flush()
        self.send(command.value)

    def send_command_data_and_read(
        self, command: Command, data: int, log: bool = False
    ) -> bytes:
        self.send_command(command)
        self.send(data)

        retval = self.read_all()
        if log:
            print(f"- {command.name:s}[{data:03d}] => {retval.hex():s}")

        return retval

    def start(self) -> None:
        if not self.serial.is_open:
            self.serial.open()

        self.send_command(Command.Start)

    def stop(self) -> None:
        self.send_command(Command.Stop)
        self.serial.close()

    def get_sensors_packets(self, packet_id: SensorPackets, log: bool = False) -> bytes:
        return self.send_command_data_and_read(Command.Sensors, packet_id.value, log)

    def log_sensors_packets(
        self, packet_id: SensorPackets | list[SensorPackets]
    ) -> None:
        match packet_id:
            case list():
                for p in packet_id:
                    self.log_sensors_packets(p)

            case SensorPackets():
                self.get_sensors_packets(packet_id, True)

            case _:
                ...

    def get_header(self) -> str:
        header = "| ID  |"
        separator = "|:---:!"
        for packet, (size, _) in RoombaSerial.SNSR_PCKT_META.items():
            header += f" {packet.value:02d} |"
            separator += ":--:|"
            for _ in range(size - 1):
                header += "    |"
                separator += ":--:|"

        return "\n".join([header, separator])

    def get_line(self, packet_id: SensorPackets) -> str:
        line = f"| {packet_id.value:>3d} |"
        values = self.get_sensors_packets(packet_id)

        if packet_id in RoombaSerial.SNSR_PCKT_GROUP_META.keys():
            start, stop = RoombaSerial.SNSR_PCKT_GROUP_META[packet_id]
            for packet, (size, _) in RoombaSerial.SNSR_PCKT_META.items():
                if packet.value < start:
                    for _ in range(size):
                        line += "    |"

            for v in values:
                line += f" {v:02X} |"

            for packet, (size, _) in RoombaSerial.SNSR_PCKT_META.items():
                if packet.value > stop:
                    for _ in range(size):
                        line += "    |"

        elif packet_id in RoombaSerial.SNSR_PCKT_META.keys():
            for packet, (size, _) in RoombaSerial.SNSR_PCKT_META.items():
                if packet_id == packet:
                    for v in values:
                        line += f" {v:02X} |"
                else:
                    for _ in range(size):
                        line += "    |"

        return line

    def get_lines(self, packet_ids: list[SensorPackets]) -> list[str]:
        return [self.get_line(packet_id) for packet_id in packet_ids]

    def print_header(self) -> None:
        print(self.get_header())

    def print_line(self, packet_id: SensorPackets) -> None:
        print(self.get_line(packet_id))

    def print_lines(self, packet_ids: list[SensorPackets]) -> None:
        print("\n".join(self.get_lines(packet_ids)))

    def spin(self, packet_id: SensorPackets, new_line: bool = True) -> None:
        try:
            while True:
                values = self.get_sensors_packets(packet_id)
                print(
                    "".join([f"{v:02X}" for v in values]),
                    end="\n" if new_line else "\r",
                )
        except KeyboardInterrupt:
            ...

    def unpack_spin(self, packet_id: SensorPackets, new_line: bool = True) -> None:
        fmt = "xx"
        if packet_id in RoombaSerial.SNSR_PCKT_META.keys():
            _, fmt = RoombaSerial.SNSR_PCKT_META[packet_id]
        elif packet_id in RoombaSerial.SNSR_PCKT_GROUP_META.keys():
            s, e = RoombaSerial.SNSR_PCKT_GROUP_META[packet_id]
            for i in range(s, e + 1):
                _, f = RoombaSerial.SNSR_PCKT_META[SensorPackets(i)]
                fmt += f
        fmt += "xxxxxx"
        try:
            while True:
                buffer = self.get_sensors_packets(packet_id)
                print(len(buffer))
                print(struct.unpack(fmt, buffer))
        except KeyboardInterrupt:
            ...

    def full_spin(self) -> None:
        try:
            while True:
                buffer = self.get_sensors_packets(SensorPackets.Group7to58)
                print(len(buffer))
                print("".join([f"{v:02X}" for v in buffer]))
                packet = struct.unpack(
                    "=BBBBBBBBBBBhhBHhxbxHHHHHHHhbBBBBBhhhhhhBHHHHHHBBhhhhBxxxxxxxxxxxx",
                    buffer,
                )
                (
                    bumps_and_wheel_drops,
                    wall,
                    cliff_left,
                    cliff_front_left,
                    cliff_front_right,
                    cliff_right,
                    virtual_wall,
                    wheel_overcurrents,
                    dirt_detect,
                    # _,
                    ir_byte_omni,
                    buttons,
                    distance,
                    angle,
                    charging_state,
                    voltage,
                    current,
                    battery_temperature,
                    battery_charge,
                    battery_capacity,
                    wall_signal,
                    cliff_left_signal,
                    cliff_front_left_signal,
                    cliff_front_right_signal,
                    cliff_right_signal,
                    _,
                    _,
                    charging_sources_availab,
                    oi_mode,
                    song_number,
                    song_playing,
                    number_of_stream_packets,
                    requested_velocity,
                    requested_radius,
                    requested_right_velocity,
                    requested_left_velocity,
                    left_encoder_counts,
                    right_encoder_counts,
                    light_bumper,
                    light_bump_left_signal,
                    light_bump_front_left_sign,
                    light_bump_center_left_sign,
                    light_bump_center_right_si,
                    light_bump_front_right_sign,
                    light_bump_right_signal,
                    ir_byte_left,
                    ir_byte_right,
                    left_motor_current,
                    right_motor_current,
                    main_brush_current,
                    side_brush_current,
                    stasis,
                    *_,
                ) = packet
                print(
                    f"{bumps_and_wheel_drops=:} | {wall=:} | {cliff_left=:} | {cliff_front_left=:} | {cliff_front_right=:} | {cliff_right=:} | {virtual_wall=:} | {wheel_overcurrents=:} | {dirt_detect=:}"
                )
                print(
                    f"{ir_byte_omni=:} | {buttons=:} | {distance=:} | {angle=:} | {charging_state=:}"
                )
                print(
                    f"{voltage=:} | {current=:} | {battery_temperature=:} | {battery_charge=:} | {battery_capacity=:}"
                )
                print(
                    f"{wall_signal=:} | {cliff_left_signal=:} | {cliff_front_left_signal=:} | {cliff_front_right_signal=:} | {cliff_right_signal=:}"
                )
                print(
                    f"{charging_sources_availab=:} | {oi_mode=:} | {song_number=:} | {song_playing=:} | {number_of_stream_packets=:}"
                )
                print(
                    f"{requested_velocity=:} | {requested_radius=:} | {requested_right_velocity=:} | {requested_left_velocity=:}"
                )
                print(f"{left_encoder_counts=:} | {right_encoder_counts=:}")
                print(
                    f"{light_bumper=:} | {light_bump_left_signal=:} | {light_bump_front_left_sign=:} | {light_bump_center_left_sign=:} | {light_bump_center_right_si=:} | {light_bump_front_right_sign=:} | {light_bump_right_signal=:}"
                )
                print(
                    f"{ir_byte_left=:} | {ir_byte_right=:} | {left_motor_current=:} | {right_motor_current=:} | {main_brush_current=:} | {side_brush_current=:} | {stasis=:}"
                )
                print()
                print()

        except KeyboardInterrupt:
            ...


def table_mode() -> None:
    with RoombaSerial() as s:
        s.print_header()
        s.print_lines(list(SensorPackets))


def live_mode() -> None:
    with RoombaSerial() as s:
        s.spin(SensorPackets.Group43to58, False)


def unpack_mode() -> None:
    with RoombaSerial() as s:
        s.unpack_spin(SensorPackets.Group7to58, False)


def full_mode() -> None:
    with RoombaSerial() as s:
        s.full_spin()


def get_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "mode",
        type=str,
        choices=["table", "live", "unpack", "full"],
        help="The mode to launch the tool in.",
    )
    return parser.parse_args()


def main() -> None:
    args = get_args()
    if args.mode == "table":
        table_mode()
    elif args.mode == "live":
        live_mode()
    elif args.mode == "unpack":
        unpack_mode()
    elif args.mode == "full":
        full_mode()


if __name__ == "__main__":
    main()
