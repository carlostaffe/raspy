// button.c
//
// Example program for pigpio library
// Pool a pin for a pressed button every 0.5 secs
//
// with something like:
// gcc -o button button.c -lpigpio -lrt
// sudo ./button
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

	gpioSetPullUpDown(4, PI_PUD_UP);   // Sets a pull-up.
        // Set the pin to be an output
        gpioSetMode(4, PI_INPUT);  // Set GPIO04 as input.
	while (1)
	{
	// Turn it on
	    printf("GPIO04 is level %d \n", gpioRead(04));
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
