
# FILOSOFOS
## Índice

1. [Introducción](#introduccion)
2. [Nuevas funciones](#nuevas-funciones)
	- [Función pthread_create](#funcion-pthread_create)
	- [Función pthread_join](#funcion-pthread_join)
3. [Main de ejemplo](#main-de-ejemplo)

### Introducción
- Para empezar a usar hilos debemos incluir la libreria : `<pthread.h>`
	- Para ello vamos a usar en el makefile una flag extra para compilar:
	```Makefile
	cc  $(CFLAGS)  -lpthread bin/libft.a  $(SRC) -o $(NAME) 
	```
	así se vería en mi makefile

### Nuevas funciones

- Para todas las funciones nuevas vamos a usar la variable `pthread_t`.
	- Se utiliza para crear, gestionar y controlar hilos en un programa multihilo. A cada hilo en un programa se le asigna un identificador único `pthread_t`, que se puede utilizar para realizar diversas operaciones en el hilo, como crearlo, unirlo, desvincularlo o cancelarlo.

#### Función pthread_create

- Función `int pthread_create(pthread_t *restrict thread,
						  const pthread_attr_t *restrict attr,
						  void *(*start_routine)(void *),
						  void *restrict arg); `
	- El primer parámetro debe ser la dirección de memoria de la variable previamente explicada atrás.
	- El segundo parámetro es un puntero a una estructura pthread_attr_t, que se utiliza para especificar los atributos del hilo que se va a crear. En este proyecto en particular, no se utilizarán atributos especiales, por lo que puedes pasar NULL para indicar que no se van a modificar los atributos del hilo.
	- El tercer parámetro es la función que se utilizará con el hilo creado precedido con & para pasar la dirección de memoria, la función TIENE QUE TENER este prototipo: `void * nombre_funcion(void *)` el hilo ejecutará esta función.
	- El cuarto parámetro es un puntero a los argumentos que se pasarán a la función especificada en el tercer parámetro. Puedes pasar NULL si no necesitas pasar ningún argumento.

#### Función pthread_join

- Función `int pthread_join(pthread_t thread, void **retval)`
	- Esta función espera a que acabe el hilo que pasamos por el primer argumento.
	- El segundo valor se pasa por `&` y se cambiará dentro del hilo gracias a la función `void pthread_exit(void * retval );`
		- Finaliza el hilo y devuelve el valor a través de retval que si hay un siguiente hilo esta disponible para el siguiente.

[Subir](#filosofos)
### Main de ejemplo

# [Main de ejemplo](srcs/hilos00.c)

```c
#include "../includes/philo.h"

void ft_error(char *str)
{
    printf("%s\n", str);
    exit(1);
}

void *print(void *arg)
{
    printf("Hola desde hilos\n %s\n",(char *)arg);
	sleep(3);
    int *resultado = malloc(sizeof(int));
    *resultado = 10;
	printf("Hilo terminado\n");
    pthread_exit(resultado);
    return (NULL);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    void * valor_devuelto;
    char *str = "variable de hilo\n";
    char *str2 = "variable de hilo2\n";

    printf("proyecto Hilos\n");
    pthread_t thread;
	pthread_t thread2;
    if (pthread_create(&thread, NULL, &print,str) != 0)
        ft_error("Error al crear el hilo\n");
    if (pthread_create(&thread2, NULL, &print,str2) != 0)
        ft_error("Error al crear el hilo\n");    
    if (pthread_join(thread, &valor_devuelto) != 0)
        ft_error("Error al esperar por el hilo\n");
        
    if (pthread_join(thread2, &valor_devuelto) != 0)
        ft_error("Error al esperar por el hilo\n");
        
    int res = *(int *)valor_devuelto;
    printf("el resultado devuelto por el hilo %d\n", res);
    free(valor_devuelto);
    return (0);
}
```
``` bash
proyecto Hilos
Hola desde hilos
 variable de hilo

Hola desde hilos
 variable de hilo2

Hilo terminado
Hilo terminado
el resultado devuelto por el hilo 10
```
[Subir](#filosofos)
