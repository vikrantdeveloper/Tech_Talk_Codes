# Free RTOS Demo session

This example demonstrates how to utilize FreeRTOS of ESP32 by echoing back to sender "hello world" and Blinking the LED at same time.

## How to use example

### Hardware Required

The example can be run on any ESP32 development board connected to a PC with a single USB cable for flashing and
monitoring.

### Setup the Hardware

No external Hardware is required

### Configure the project

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

(To exit the serial monitor, type ``Ctrl-]``.)

See the Getting Started Guide for full steps to configure and use ESP-IDF to build projects.

## Troubleshooting

vTaskDelay is neccessary in both the parallel task as they otherwise it will crash
