/*  
 ** Programa: send.c 
 **  
 ** Objetivo: Mostrar el "send" de mensajes a una cola de mensajes
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
#include <sys/mman.h>
#include <mqueue.h>
#include <string.h>


int main( int argc , char * argv[]) {	
        if (argc != 2){
                fprintf(stderr, "ERROR: uso %s <mensaje> \n", argv[0]);
                return 255;
        }
	int retorna;
	// cuarto parametro de mq_send es unsigned
	size_t prior;
	prior = 1;
	mqd_t mqd;
	// abro cola de mensajes existente
	mqd = mq_open( "/api-control" , O_RDWR | O_CREAT , 0777 , NULL );
	if (( mqd < 0 )){
		perror ("mq_open()");
		return -1;
	}
	// envia valor 
        retorna = mq_send(mqd,argv[1],strlen(argv[1]),prior);
	if (( retorna < 0 )){
		perror ("mq_send()");
		return -1;
	}
	printf ("encolado ok\n");
	return 0;
}
