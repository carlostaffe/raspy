
#include <pigpio.h>


int activa_motor()
{
	if (gpioInitialise() < 0)
	{
	   // pigpio initialisation failed.
	   return -1;
	}
	// Set the pin to be an output
	gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
	gpioWrite(14, 1); // Set GPIO14 high.
	// wait a bit
	gpioSleep(PI_TIME_RELATIVE, 0, 500000); // sleep for 0.5 seconds


	gpioWrite(14, 0); // Set GPIO14 low.
	// wait a bit
    return 0;
}

