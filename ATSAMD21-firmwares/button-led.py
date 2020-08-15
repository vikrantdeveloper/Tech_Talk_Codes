# Write your code here :-)
import time
from adafruit_circuitplayground.express import cpx
import analogio
import board
import simpleio

cpx.pixels.brightness =0.1
cpx.pixels.fill((0,0,0))
cpx.pixels.show()                                   # sends data to pixels
#light = analogio.AnalogIn(board.A8)

while True:                            # loop
    if cpx.button_b:                   # if button is pushed then everything in hanging indent is executed
        print("Button B Pressed!")     # prints text in the serial monitor
        cpx.pixels[0] = (255, 0, 0)