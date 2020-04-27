from gpiozero import Button
from time import sleep
#GPIO4  (pin 7)
boton = Button(4,pull_up=False)

while True:
    sleep(1)
    if boton.is_pressed:
        print "pulsado"
    else:
        print "no pulsado"
