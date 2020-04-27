#!/bin/bash
# uso de la GPIO17 ...mapeada al pin 11 -> led
# uso de la GPIO4 ...mapeada al pin 7   <- pulsador
#inicializo
echo "17" > /sys/class/gpio/unexport
echo "4" > /sys/class/gpio/unexport
# escritura (salida)
echo "17" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio17/direction
# lectura (entrada)
echo "4" > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio4/direction

while [ True ]
do
    sleep 1;
	echo "0" > /sys/class/gpio/gpio17/value
    sleep 1;
	cat /sys/class/gpio/gpio4/value
	echo "1" > /sys/class/gpio/gpio17/value
done
echo "17" > /sys/class/gpio/unexport
echo "4" > /sys/class/gpio/unexport
