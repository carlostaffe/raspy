#include <pigpio.h>


int entra_a_cinta()
{
	if (gpioInitialise() < 0)
	{
	   // pigpio initialisation failed.
	   return -1;
	}

	gpioSetPullUpDown(4, PI_PUD_UP);   // Sets a pull-up.
        // Set the pin to be an output
        gpioSetMode(4, PI_INPUT);  // Set GPIO04 as input.
	// Read some data
	uint8_t value = gpioRead(04);
        // wait a bit
        gpioSleep(PI_TIME_RELATIVE, 0, 200000); // sleep for 0.5 seconds
	
    return value;
}

