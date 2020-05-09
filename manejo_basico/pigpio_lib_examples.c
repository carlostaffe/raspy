

if (gpioInitialise() < 0)
{
   // pigpio initialisation failed.
}
else
{
   // pigpio initialised okay.
}


gpioSetPullUpDown(17, PI_PUD_UP);   // Sets a pull-up.

gpioSetPullUpDown(18, PI_PUD_DOWN); // Sets a pull-down.

gpioSetPullUpDown(23, PI_PUD_OFF);  // Clear any pull-ups/downs.


gpioSetMode(17, PI_INPUT);  // Set GPIO17 as input.

gpioSetMode(18, PI_OUTPUT); // Set GPIO18 as output.

gpioSetMode(22,PI_ALT0);    // Set GPIO22 to alternative mode 0.



printf("GPIO24 is level %d", gpioRead(24));

gpioWrite(24, 1); // Set GPIO24 high.


gpioSleep(PI_TIME_RELATIVE, 2, 500000); // sleep for 2.5 seconds

gpioSleep(PI_TIME_RELATIVE, 0, 100000); // sleep for 0.1 seconds

gpioSleep(PI_TIME_RELATIVE, 60, 0);     // sleep for one minute

