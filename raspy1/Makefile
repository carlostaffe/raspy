CFLAGS = -Wall -pthread
LIBS =   -l bcm2837

hilo-prod-cons: hilo-prod-cons.o activa_motor.o produce_cinta.o
	gcc $(CFLAGS)  -o $(@) $(^) $(LIBS)
