# Model-N Thermostat Firmware
STM8 Firmware replacement for the popular Model N radiator thermostats (sold under the eQ-3 eqiva brand). It provides a UART interface through the MP1(PA3) and MP2(PA2) pads on the board, intended to be controlled from an additional controller/system. For example an ESP8266 or ESP32 to provide WLAN and Bluetooth 4.0 connectivity.
The stock LCD and buttons are not implemented (so far).

### Build
SDCC is recommended for compiling the code. It can be executed with the correct arguments through the `build.sh` script. A build config is also included to conveniently use the Atom Editor with build plugin.

### Flashing
Connect a ST-Link V2 to corresponding PRG1 (SWIM) pads on the board. Then flash the `thermo.hex` onto the STM8L052C6.
Important Note: stm8flash requires to specify stm8l152c6 as part instead of stm8l052c6 for it to work, so use: `stm8flash -c stlinkv2 -p stm8l152c6 -w thermo.hex`

### UART interface
(coming soon)

### Credits
Schematic (thanks!): https://www.mikrocontroller.net/topic/359741
