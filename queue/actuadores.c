#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <pigpio.h>

int main (){
	typedef enum {false,true} bool_t;
	bool_t actuador[10];
	int i;
	for (i=0;i<10;i++){	//inicializa las salidas en bajo
		actuador[i] = false;
	}
	gpioInitialise();
  	gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
	gpioWrite(14, 0); // Set GPIO14 low.
	//abro cola
	//
	
	while (1){
		printf("\e[1;1H\e[2J");
		for (i=0;i<10;i++){	
			printf("actuador %d = %d\n",i,actuador[i]);
			}
		//leo colad
		if (nro_actuador == 99 ) kill(getpid(),2); //me suicidio
		if (actuador[nro_actuador] == false) actuador[nro_actuador] = true; else actuador[nro_actuador] = false;
		if (nro_actuador == 5) {if (actuador[5] == false) gpioWrite(14, 0); else gpioWrite(14, 1);} //cambia el estado SOLO si se oprime 5
	return 0;
}
