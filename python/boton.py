#!/usr/bin/python3 
from gpiozero import Button
from time import sleep

button = Button(4)
print  ("apretar para que arranque el bucle")
button.wait_for_press()
while True:
    if button.is_pressed:
        print("Pressed")
    else:
        print("Released")
    sleep(1)

