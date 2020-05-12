#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <pigpio.h>

typedef enum {false,true} bool_t;
bool_t actuador[10];

void *lee_teclas_actua() {
	int nro_actuador;
	while (1){
		scanf("%d", &nro_actuador);
		if (nro_actuador == 99 ) kill(getpid(),2); //termina el proceso
		if (actuador[nro_actuador] == false) actuador[nro_actuador] = true; else actuador[nro_actuador] = false;
		if (nro_actuador == 5) {if (actuador[5] == false) gpioWrite(14, 0); else gpioWrite(14, 1);} //cambia el estado SOLO si se oprime 5
	}
	pthread_exit(NULL);
}
void *visualiza() {
	int i;
	while (1){
		for (i=0;i<10;i++){	
			printf("actuador %d = %d\n",i,actuador[i]);
			}
		printf ("esperando entradas \n");
		sleep(1);
		printf("\e[1;1H\e[2J");
		}
	pthread_exit(NULL);
}
int main (){
	int i;
	pthread_t tid1;
	pthread_t tid2;
	printf("\e[1;1H\e[2J");
	for (i=0;i<10;i++){	//inicializa las salidas en bajo
		actuador[i] = false;
	}
	gpioInitialise();
  	gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
	gpioWrite(14, 0); // Set GPIO14 low.
	pthread_create (&tid1, NULL, lee_teclas_actua, NULL);
	pthread_create (&tid2, NULL, visualiza, NULL);
	pthread_join (tid1,NULL);
	pthread_join (tid2,NULL);
	return 0;
}
