#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpio.h>

int timer = 1;

void *led() {
  printf ("Hello World! .... soy yo , el led \n");
  while (1) {
	gpioWrite(14, 1); // Set GPIO14 high.
	sleep(timer);
	gpioWrite(14, 0); // Set GPIO14 low.
	sleep(timer);
  }
  pthread_exit (NULL);
}
void *boton() {
  printf ("Hello World! .... soy yo , el boton \n");
  while (1) {
	    if (gpioRead(4) == 0 ){
		timer = timer + 1;
	    	printf ("timer = %d\n",timer);
	    }
	    sleep(1);
  }
  pthread_exit (NULL);
}

int main () {
  pthread_t tid1,tid2;
  gpioInitialise();
  gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
  gpioSetPullUpDown(4, PI_PUD_UP);   // Sets a pull-up.
  gpioSetMode(4, PI_INPUT);  // Set GPIO04 as input.
  printf ("El main ... el main booteando ....\n");
  pthread_create (&tid1, NULL, led, NULL);
  pthread_create (&tid2, NULL, boton, NULL);
  pthread_join (tid1,NULL);
  pthread_join (tid2,NULL);
  printf ("terminaron los hilos ...\n");
  return 0;
}
