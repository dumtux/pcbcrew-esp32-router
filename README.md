# ESP-IDF Project for Wi-Fi, Ethernet, and 4G/LTE Network Router

* Tested using [ESP-IDF framework version 5.0][esp-idf-v5.0]

## Overview

**Note:** 4G LTE network routing is still work-in-progress.

## How to use example

### Hardware Required

| [PCBCrew Easymeal IoT][pcbcrew-easymeal-iot]                       | [PCBCrew BLDGOT kWh][pcbcrew-bldgot-kwh]                            | [ESP32-Ethernet-Kit][esp32-ethernet-kit]                       |
| ------------------------------------------------------------------ | ------------------------------------------------------------------- | -------------------------------------------------------------- |
| ![pcbcrew-easymeal-iot](./doc/image/pcbcrew-easymeal-iot-pcba.png) | ![pcbcrew-bldgot-kwh-pcba](./doc/image/pcbcrew-bldgot-kwh-pcba.png) | ![esp32-ethernet-kit](./doc/image/esp32-ethernet-kit-v1.2.png) |
| ESP32-S3 / W5500 / mini-PCIe                                       | ESP32-S3 / Wiznet W5500                                             | ESP32-WROVER / IP101                                           |

### Configure the project

```
idf.py menuconfig
```

In addition to the common configurations for Ethernet, you might also need to update the default value of following configurations:

In the `Example Configuration` menu:
* Set the SSID and password for Wi-Fi ap interface under `Wi-Fi SSID` and `Wi-Fi Password`.
* Set the maximum connection number under `Maximum STA connections`.

### Build, Flash, and Run

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT build flash monitor
```

## References

* [ESP-IDF eth2ap Example][eth2ap]
* [ESP-IoT-Bridge Solution][esp-iot-bridge]


[esp-idf-v5.0]: https://github.com/espressif/esp-idf/tree/release/v5.0
[eth2ap]: https://github.com/espressif/esp-idf/tree/release/v5.0/examples/ethernet/eth2ap
[esp-iot-bridge]: https://github.com/espressif/esp-iot-bridge
[pcbcrew-easymeal-iot]: https://github.com/dumtux/pcbcrew-easymeal-iot
[pcbcrew-bldgot-kwh]: https://github.com/dumtux/pcbcrew-bldgot-kwh
[esp32-ethernet-kit]: https://github.com/espressif/esp-idf/blob/master/docs/en/hw-reference/esp32/get-started-ethernet-kit.rst
