from gpiozero import LED
from time import sleep
#GPIO17 (pin 11)
led = LED(17)

while True:
    led.on()
    print "prende"
    sleep(1)
    led.off()
    print "apaga"
    sleep(1)
