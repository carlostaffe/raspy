#include <bcm2835.h>

// Input on RPi pin GPIO 07
#define PIN RPI_GPIO_P1_07

int produce_cinta()
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
	return 1;

    // Set RPI pin P1-07 to be an input
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
    //  with a pullDOWN
    bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_DOWN);

	// Read some data
	uint8_t value = bcm2835_gpio_lev(PIN);
	
	// wait a bit
	delay(200);

    return value;
}

