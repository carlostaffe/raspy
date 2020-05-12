CFLAGS = -Wall 
LDLIBS= -lpigpio  -lpthread

hilo-prod-cons: hilo-prod-cons.o activa_motor.o entra_a_cinta.o
	gcc $(CFLAGS)  -o $(@) $(^) $(LDLIBS)
