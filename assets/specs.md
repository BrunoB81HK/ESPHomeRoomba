# iRobot Open Interface Specification

This document provide a simple and efficient description of the iRobot Open Interface Specification.

# Sensor Packets Groups

## *<**0**>* Packets 7 to 26

> **Size:** 26 bytes

```wavedrom
{
  config: {vflip: true, hflip: true, lanes: 13},
  reg: [
    {"bits": 1, type: 2, "name": "BumpR"},
    {"bits": 1, type: 2, "name": "BumpL"},
    {"bits": 1, type: 2, "name": "WDropR"},
    {"bits": 1, type: 2, "name": "WDropL"},
    {"bits": 4, type: 1},
    {"bits": 1, type: 3, "name": "Wall"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 4, "name": "CliffL"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 4, "name": "CliffFL"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 4, "name": "CliffFR"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 4, "name": "CliffR"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 3, "name": "VWall"},
    {"bits": 7, type: 1},
    {"bits": 1, type: 5, "name": "SBrush"},
    {"bits": 1, type: 1},
    {"bits": 1, type: 5, "name": "MBrush"},
    {"bits": 1, type: 5, "name": "RWheel"},
    {"bits": 1, type: 5, "name": "LWheel"},
    {"bits": 3, type: 1},
    {"bits": 8, type: 6, "name": "Dirt Detect"},
    {"bits": 8, type: 1},
    {"bits": 8, type: 7, "name": "Infrared Char Omni"},
    {"bits": 1, type: 2, "name": "Clean"},
    {"bits": 1, type: 2, "name": "Spot"},
    {"bits": 1, type: 2, "name": "Dock"},
    {"bits": 1, type: 2, "name": "Min"},
    {"bits": 1, type: 2, "name": "Hr"},
    {"bits": 1, type: 2, "name": "Day"},
    {"bits": 1, type: 2, "name": "Sched"},
    {"bits": 1, type: 2, "name": "Clock"},
    {"bits": 16, type: 3, "name": "Distance"},
    {"bits": 16, type: 4, "name": "Angle"},
    {"bits": 8, type: 5, "name": "Charging State"},
    {"bits": 16, type: 6, "name": "Voltage"},
    {"bits": 16, type: 7, "name": "Current"},
    {"bits": 8, type: 2, "name": "Temperature"},
    {"bits": 16, type: 3, "name": "Battery Charge"},
    {"bits": 16, type: 4, "name": "Battery Capacity"},
  ]
}
```

```wavedrom
{
  config: {vflip: true, hflip: true, lanes: 6},
  reg: [
    {"bits": 1, type: 2, "name": "Bumps and Wheel Drops"},
    {"bits": 1, type: 3, "name": "Wall"},
    {"bits": 1, type: 4, "name": "Cliff Left"},
    {"bits": 1, type: 4, "name": "Cliff Front Left"},
    {"bits": 1, type: 4, "name": "Cliff Front Right"},
    {"bits": 1, type: 4, "name": "Cliff Right"},
    {"bits": 1, type: 3, "name": "Virtual Wall"},
    {"bits": 1, type: 5, "name": "Wheel Overcurrents"},
    {"bits": 1, type: 6, "name": "Dirt Detect"},
    {"bits": 1, type: 1},
    {"bits": 1, type: 7, "name": "Infrared Char Omni"},
    {"bits": 1, type: 2, "name": "Buttons"},
    {"bits": 2, type: 3, "name": "Distance"},
    {"bits": 2, type: 4, "name": "Angle"},
    {"bits": 1, type: 5, "name": "Charging State"},
    {"bits": 2, type: 6, "name": "Voltage"},
    {"bits": 2, type: 7, "name": "Current"},
    {"bits": 1, type: 2, "name": "Temperature"},
    {"bits": 2, type: 3, "name": "Battery Charge"},
    {"bits": 2, type: 4, "name": "Battery Capacity"},
  ]
}
```

ljdhbvlkhdsfb

```wavedrom
{
  config: {vflip: true, hflip: true, lanes: 4},
  reg: [
    {"name": "7: djfjd", "attr": "uint8", "bits": 8, type: 1},
    {"name": "8: djfjd", "attr": "uint8", "bits": 8, type: 4},
    {"name": "9: djfjd", "attr": "uint8", "bits": 8, type: 5},
    {"name": "10: djfjd", "attr": "uint8", "bits": 8, type: 6},
    {"name": "11: djfjd", "attr": "uint8", "bits": 8, type: 7},
    {"name": "12: djfjd", "attr": "uint8", "bits": 8, type: 8},
    {"name": "13: djfjd", "attr": "uint8", "bits": 8, type: 9},
    {"name": "14: djfjd", "attr": "uint8", "bits": 8, type: 3},
    {"name": "15: djfjd", "attr": "uint8", "bits": 8, type: 4},
    {"name": "16: djfjd", "attr": "uint8", "bits": 8, type: 5},
    {"name": "17: djfjd", "attr": "uint8", "bits": 8, type: 6},
    {"name": "18: djfjd", "attr": "uint8", "bits": 8, type: 7},
    {"name": "19: djfjd", "attr": "uint8", "bits": 8, type: 8},
    {"name": "20: djfjd", "attr": "uint8", "bits": 8, type: 9},
    {"name": "21: djfjd", "attr": "uint8", "bits": 8, type: 3},
    {"name": "22: djfjd", "attr": "uint8", "bits": 8, type: 4},
    {"name": "23: djfjd", "attr": "uint8", "bits": 8, type: 5},
    {"name": "24: djfjd", "attr": "uint8", "bits": 8, type: 6},
    {"name": "25: djfjd", "attr": "uint8", "bits": 8, type: 7},
    {"name": "26: djfjd", "attr": "uint8", "bits": 8, type: 8},
  ]
}
```


Group7to26 = 0,                   // Size: 26 packets
  Group7to16 = 1,                   // Size: 10 packets
  Group17to20 = 2,                  // Size: 6 packets
  Group21to26 = 3,                  // Size: 10 packets
  Group27to34 = 4,                  // Size: 14 packets
  Group35to42 = 5,                  // Size: 12 packets
  Group7to42 = 6,                   // Size: 52 packets
  Group7to58 = 100,                 // Size: 80 packets
  Group43to58 = 101,                // Size: 28 packets
  Group46to52 = 106,                // Size: 12 packets
  Group54to58 = 107,                // Size: 9 packets

# Commands

## ***Start***

>  **OPCODE:** 128 | 0x80

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 128, "attr": "OPCODE", type: 5},
  ]
}
```

## ***Reset***

>  **OPCODE: 7 | 0x07**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 7, "attr": "OPCODE", type: 5},
  ]
}
```

## ***Stop***

>  **OPCODE: 173 | 0xAD**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 173, "attr": "OPCODE", type: 5},
  ]
}
```

## ***Baud***

>  **OPCODE: 129 | 0x81**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 400},
  reg: [
    {"bits": 8, "name": 129, "attr": "OPCODE", type: 5},
    {"bits": 8, "name": "", attr: "BAUD CODE", type: 6},
  ]
}
```

| CODE | Baud Rate |
| ---: | :-------: |
|    0 |    300    |
|    1 |    600    |
|    2 |   1200    |
|    3 |   2400    |
|    4 |   4800    |
|    5 |   9600    |
|    6 |   14400   |
|    7 |   19200   |
|    8 |   28800   |
|    9 |   38400   |
|   10 |   57600   |
|   11 |  115200   |

## ***Control***

>  **OPCODE: 130 | 0x82**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 130, "attr": "OPCODE", type: 5},
  ]
}
```

## ***Safe***

>  **OPCODE: 131 | 0x83**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 131, "attr": "OPCODE", type: 5},
  ]
}
```

## ***Full***

>  **OPCODE: 132 | 0x84**

```wavedrom
{
  config: {vflip: true, label: {left: "Sent"}, margin: {left: 40}, hspace: 200},
  reg: [
    {"bits": 8, "name": 132, "attr": "OPCODE", type: 5},
  ]
}
```
