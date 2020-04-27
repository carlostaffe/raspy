// blink.c
//
// Example program for pigpio library
// Blinks a pin on an off every 0.5 secs
//
// with something like:
// gcc -o blink blink.c -lpigpio -lrt
// sudo ./blink
//

#include <pigpio.h>
#include <stdio.h>


int main(int argc, char **argv)
{

	if (gpioInitialise() < 0)
	{
	   // pigpio initialisation failed.
	   printf ("error\n");
	   return -1;
	}
	else
	{
	   printf ("inicializo\n");
	   // pigpio initialised okay.
	}

    // Set the pin to be an output
    gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.

    // Blink
    while (1)
    {
	// Turn it on
	gpioWrite(14, 1); // Set GPIO14 high.
	printf("alto\n");	
	// wait a bit
	gpioSleep(PI_TIME_RELATIVE, 0, 500000); // sleep for 0.5 seconds
	
	// turn it off
	gpioWrite(14, 0); // Set GPIO14 low.
	printf("bajo\n");	
	// wait a bit
	gpioSleep(PI_TIME_RELATIVE, 0, 500000); // sleep for 0.5 seconds
    }

    return 0;
}


/*
gpioSetMode(14, PI_INPUT);  // Set GPIO14 as input.
gpioSetMode(18, PI_OUTPUT); // Set GPIO18 as output.

gpioSetMode(22,PI_ALT0);    // Set GPIO22 to alternative mode 0.

printf("GPIO24 is level %d", gpioRead(24));

*/
