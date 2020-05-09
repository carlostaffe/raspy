#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <pthread.h>

typedef enum {false,true} bool_t;
bool_t actuador[10];

void *sensores() {
	int nro_actuador;
	int i;
	while (1){
		scanf("%d", &nro_actuador);
		if (actuador[nro_actuador] == false) actuador[nro_actuador] = true; else actuador[nro_actuador] = false;
	}
	pthread_exit(NULL);
}
void *actuadores() {
	int i;
	while (1){
		for (i=0;i<10;i++){	
			printf("actuador %d = %d\n",i,actuador[i]);
			}
		printf ("esperando entradas\n");
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
	pthread_create (&tid1, NULL, sensores, NULL);
	pthread_create (&tid2, NULL, actuadores, NULL);
	pthread_join (tid1,NULL);
	pthread_join (tid2,NULL);
	return 0;
}
