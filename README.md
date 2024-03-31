# LOS FILOSOFOS

## EN CONSTRUCION
	
- [ENLACE A LA EXPLICACION DE FUNCIONES y los problemas de los hilos 3 Readmes para disfrutar](EXPLICACIONES.md)
- Varios enlaces de interes / fuentes
	- [Hilos](https://cs341.cs.illinois.edu/coursebook/Threads)
	- [Mutex](https://cs341.cs.illinois.edu/coursebook/Synchronization)
	- [Puntos Muertos](https://cs341.cs.illinois.edu/coursebook/Deadlock)
# Parte 1 inicializar los Mutex e hilos
- Lo primero que hago es mallocar memoria para cada struct philo que vaya a necesitar (numero de filos )

- Lo segundo que hago es allocar memoria para cada tenedor(que van a ser mis mutex) y los inicializamos.
- Por tenemas de legibilad y no tener que escribir cada vez la funcion 
	`pthread_mutex_init` he hecho una funcion wrappeada llamada
	`action_mutex_init`.
	- se pueden ver [aqui](srcs/wrapped_mutex.c) mis funciones de wrapeo
	y en el [header](includes/philo.h) un enum con todos los tipos de mutex que tengo para que quede asi:
```c
action_mutex_init(data, PRINT)
```
[Subir](#los-filosofos)
### Iniciazalizacion de los hilos 
- Bucle para inicializar cada struct, lo nuevo aqui aparte de la funcion `pthread_crate`(explicada en los readmes de [funciones](EXPLICACIONES.md)) es get_time() una funcion que llama a una de las funciones permitidas que es 
	`gettimeofday``
```c
#include <stdio.h>
#include <sys/time.h>


int main()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("Seconds since Jan. 1, 1970: %ld\n", tv.tv_sec);
	printf("Microseconds: %ld\n", tv.tv_usec);
	return (0);
}
```
```bash
Seconds since Jan. 1, 1970: 1711855062
Microseconds: 765366
```
- Ademas simulo una mesa redonda  para garantizar que el tenedor del ultimo filosofo sea el 0
[Subir](#los-filosofos)
### Detach y bucle while
- Aqui viene la primera decision se podra usar un 
`pthread_join` y esperar a que todos los hilos terminen,
entonces habria que crear un hilo para checkear muertes de filosofos y si en el caso de que te pasen un numero de comidas y todos han comido vaya comprobando o utilizar la funcion `pthread_detach` que en mi caso es la opcion ya que no espera a que acaben los hilos y el codigo por debajo se ejecuta a la par he tenido varios problemas de syncro por el camino , pero nada grave mi hermano, al final los hilos se van ejecutando mientras tengo un bonito while(42) comprobando tanto alguna muerte como si todos han comido y tenemos que acabar el programa.
## continua en el siguiente readme[Rutina->](Rutina.md)
## Pensamientos dibujados y problemas resueltos

![alt text](filos.png)
