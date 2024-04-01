
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t semaphore;

void* thread_function(void* arg) {
	// Esperar al semáforo
	sem_wait(&semaphore);
	sleep(1);
	// Sección crítica
	printf("Sección crítica ejecutada por el hilo %ld\n", (long)arg);

	// Liberar el semáforo
	sem_post(&semaphore);
	printf("Sección crítica liberada por el hilo %ld\n", (long)arg);

}

int main() {
	int num_threads = 5;
	pthread_t threads[num_threads];

	// Inicializar el semáforo
	sem_init(&semaphore, 0, 2);

	// Crear los hilos
	for (long i = 0; i < num_threads; i++) {
		pthread_create(&threads[i], NULL, thread_function, (void*)i);
	}

	// Esperar a que los hilos terminen
	for (int i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	// Destruir el semáforo
	sem_destroy(&semaphore);

	return 0;
}
