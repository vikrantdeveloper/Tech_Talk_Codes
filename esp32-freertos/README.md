# FreeRTOS Session

This example demonstrates how to utilize FreeRTOS of ESP32 by echoing back to sender "hello world" and blinking the LED at same time.

## How to use example

### Hardware Required

The example can be run on any ESP32 wroom connected to a PC with a single USB cable for flashing and
monitoring.

### Setup the Hardware

No external Hardware is required

### Configure the project

clone the project in the folder where esp-idf folder is there. run the script in order to build the project using the command   
. ../esp-idf/export.sh
```
idf.py menuconfig
```
or
```
idf.py menuconfig
```

* Set serial port under Serial Flasher Options.

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```
or
```
idf.py -p PORT flash monitor
```
## Troubleshooting

vTaskDelay is neccessary in both the parallel task as they otherwise it will crash
