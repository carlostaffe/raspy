/*  
 ** Programa: receive.c
 **  
 ** Objetivo: Mostrar la recepcion de datos desde una cola de mensajes
 **   
 ** Author: carlost <carlos.taffernaberry@um.edu.ar>
 ** 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

int main( int argc , char * argv[]) {	
        if (argc != 2){
                fprintf(stderr, "ERROR: uso %s </cola_mensajes> \n", argv[0]);
                return 255;
        }
	int leido;
	//struct mq_attr atri;
	char contenido[8192];
        unsigned int priori;
	mqd_t mqd;
	// abro cola de mensajes existente
// 	mqd = mq_open( argv[1] , O_RDWR | O_NONBLOCK);
	mqd = mq_open( argv[1] , O_RDWR );
	//mqd = mq_open( argv[1] , O_RDWR );
	if (mqd < 0) {
                perror("Error en la apertura de la Cola de Mensajes\n");
                return 1;
        }

	// lee un mensaje de la cola
	// en realidad hay que hacer un getattr para el size
        leido = mq_receive(mqd,contenido,8192,&priori);
       // mq_getattr(mqd , &atri);
        //        perror("Error en la lectura de la Cola de Mensajes\n");
        //
   //     printf ("valor de msg_size %ld\n",atri.mq_msgsize);
    //    leido = mq_receive(mqd,contenido,atri.mq_msgsize,&priori);
	printf("Mensaje recibido (%d bytes) de prioridad %d:\"%s\"\n", leido, priori, contenido);
	//pause();
	return 0;
}
