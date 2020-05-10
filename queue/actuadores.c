#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdlib.h>
#include <pigpio.h>

int main (){
	typedef enum {false,true} bool_t;
	bool_t actuador[10];
	int i, leido, numero, nro_actuador, tiempo;
	char *final;
	for (i=0;i<10;i++){	//inicializa las salidas en bajo
		actuador[i] = false;
	}
	gpioInitialise();
  	gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
	gpioWrite(14, 0); // Set GPIO14 low.
	//abro cola
        mqd_t mqd;
	mqd = mq_open( "/api-domotica" , O_RDWR | O_CREAT , 0777 , NULL );
	struct mq_attr atri;
	mq_getattr(mqd , &atri);
	char contenido[atri.mq_msgsize];
	printf("\e[1;1H\e[2J");
	for (i=0;i<10;i++){	
		printf("actuador %d = %d\n",i,actuador[i]);
	}
	while (1){
		//leo cola
	 	leido = mq_receive(mqd,contenido,atri.mq_msgsize,NULL);
		if (leido == 6){
		numero  = strtol(contenido,&final,10);
                if (final == contenido) {
			printf("No se encontro un nro \n");
		}
		else {
			nro_actuador = numero/1000;
			tiempo = numero%1000;
			printf ("nro_actuador  %d tiempo %d\n",nro_actuador,tiempo);
			if (nro_actuador < 10) {
				if (actuador[nro_actuador] == false) actuador[nro_actuador] = true; else actuador[nro_actuador] = false;
				if (nro_actuador == 5) {if (actuador[5] == false) gpioWrite(14, 0); else gpioWrite(14, 1);} //cambia el estado SOLO si se oprime 5
				printf("\e[1;1H\e[2J");
				for (i=0;i<10;i++){	
					printf("actuador %d = %d\n",i,actuador[i]);
				}
			}
			else { printf ("Actuador %d no implementado :-(\n",nro_actuador); }
			}
	        }
		else { printf ("No se implemento la API :-(\n"); }
	}

	return 0;
}
