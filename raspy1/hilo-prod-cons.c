/*
 ** Author: Carlos Taffernaberry <ctaffer@unsl.edu.ar> 
 **
 ** This program is free software; you can redistribute it and/or modify it
 ** under the terms of the GNU General Public License as published by the
 ** Free Software Foundation; either version 2 of the License, or (at your
 ** option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 **
 ** This program is distributed in the hope that it will be useful, but
 ** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 ** or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 ** for more details.
 **/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

int lugares = 5;
sem_t vacio;
sem_t lleno;
pthread_mutex_t exclusion = PTHREAD_MUTEX_INITIALIZER;

void *hilo_produce() {
	int produce_cinta();
	while( 1 ) {
		if ( produce_cinta() == 1 ){
				sem_wait(&vacio);
				sem_post(&lleno);
				pthread_mutex_lock(&exclusion);
				lugares--;
				printf("Produce... quedan %d lugares\n",lugares);
				pthread_mutex_unlock(&exclusion);
		}
	}
	pthread_exit(NULL);
}
void *hilo_consume() {
	void activa_motor(void);
	while( 1 ) {
		sem_wait(&lleno);
		sem_post(&vacio);
		sleep(2);
		pthread_mutex_lock(&exclusion);
		lugares++;
		printf("Consume... quedan %d lugares\n",lugares);
		//activa un motor
		activa_motor();
		pthread_mutex_unlock(&exclusion);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t hilo_p,hilo_c;
    int rc;
	sem_init(&vacio,0, 4); //inicializado en 4
	sem_init(&lleno,0, 0); //inicializado en 0
    rc = pthread_create(&hilo_c, NULL, hilo_consume, NULL);
    if (rc) {
	printf("ERROR: pthread_create() = %d\n", rc);
	exit(-1);
    }
    rc = pthread_create(&hilo_p, NULL, hilo_produce, NULL);
    if (rc) {
	printf("ERROR: pthread_create() = %d\n", rc);
	exit(-1);
    }
    pthread_exit(NULL);
    return (0);
}
