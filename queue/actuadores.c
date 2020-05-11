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
	int i, leido, numero, tmp, nro_actuador, tiempo, version;
	char *final;
	for (i=0;i<10;i++){	//inicialize in low
		actuador[i] = false;
	}
	gpioInitialise();
  	gpioSetMode(14, PI_OUTPUT);  // Set GPIO14 as OUTput.
	gpioWrite(14, 0); // Set GPIO14 low.
        mqd_t mqd;
	//mq open or create
	mqd = mq_open( "/api-control" , O_RDWR | O_CREAT , 0777 , NULL );
	struct mq_attr atri;
	mq_getattr(mqd , &atri);
	char contenido[atri.mq_msgsize];
	printf("\e[1;1H\e[2J");
	for (i=0;i<10;i++){	
		printf("actuador %d = %d\n",i,actuador[i]);
	}
	while (1){
		//blocked while mq read
	 	leido = mq_receive(mqd,contenido,atri.mq_msgsize,NULL);
		if (leido == 8){
			numero  = strtol(contenido,&final,10);
			if (final == contenido) {
				printf("No se encontro un nro \n");
			}
			else {
				version = numero/1000000;
				tmp = numero%1000000;
				nro_actuador = tmp/1000;
				tiempo = numero%1000;
				if ( version == 1 ){
					if ( nro_actuador < 10 ){
						if (actuador[nro_actuador] == false) actuador[nro_actuador] = true; else actuador[nro_actuador] = false;
						if (nro_actuador == 5) {if (actuador[5] == false) gpioWrite(14, 0); else gpioWrite(14, 1);} //change ONY if 5 is pressed
						printf("\e[1;1H\e[2J");
						for (i=0;i<10;i++){	
							printf("actuador %d = %d\n",i,actuador[i]);
						}
						printf ("version api %d  nro_actuador %d tiempo %d\n",version,nro_actuador,tiempo);
					}
					else { printf ("Actuador %d no implementado :-(\n",nro_actuador); }
				}
				
				else { printf ("Version %d no implementada :-(\n",version); }
			}
	}
	else { printf ("No se respeta la API :-(\n"); }

	}
	return 0;
}
