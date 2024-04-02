# Funciones semaforos  incluidas en  `<semaphore.h>`

### La nueva variable
sem_t

## Que es un semaforo 
Es una variable para bloquear y desbloquear partes de codigo. y nos sirve durante toda la ejecucion del programa. da igual el escope donde estes que si bloqueas ese semaforo en un hilo , ningun proceso podra pasar por donde haya un bloqueo.
- `sem_wait(sem_t *semaforo)`
	- bloquea 1 vez el paso por el semaforo
- `sem_post(sem_t *semaforo)`
	- Libera 1 vez el paso porel  semaforo

 * La función `sem_t * sem_open(const char *, int, ...)`
` 
	 se utiliza para crear o abrir un semáforo con un nombre específico.
 
	* El nombre del semáforo.
 	* Los flags de apertura del semáforo
	 	-  O_CREAT : Crea el semaforo si no existe
        - O_EXCL : Da error si el semaforo ya existia
 	*  Los permisos de acceso al semáforo.(chmod)
 	* El valor inicial del semáforo.
 
 * return El identificador del semáforo creado o abierto, o -1 en caso de error.
 
- Esto quiere decir que si creamos un semaforo con valor 5 , podremos pasar por 5 bloqueos antes de necesitaremos hacer un post para pasar por por bloqueo
