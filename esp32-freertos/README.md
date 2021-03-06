# FreeRTOS Session

This example demonstrates how to utilize FreeRTOS of ESP32 by echoing back to sender "hello world" and blinking the LED at same time.

## How to use example

### Hardware Required

The example can be run on any ESP32 wroom connected to a PC with a single USB cable for flashing and
monitoring.

### Setup the Hardware

No external Hardware is required

### Configure the project

* Clone the project in the folder where esp-idf folder is there , run the script in order to build the project using the command   
```
. ../esp-idf/export.sh
```  
* Select the chip size from 2MB to 4MB using the command which opens the menuconfig
```
idf.py menuconfig
```  

* Set serial port under Serial Flasher Options.

### Build and Flash

* Clean the project and build to observe any errors.

```
idf.py fullclean
```  
```
idf.py build
```
* Flash the firmware to the board, run the monitor to view serial output
```
idf.py -p PORT flash monitor
```
## Troubleshooting

vTaskDelay is neccessary in both the parallel task as they otherwise it will crash
