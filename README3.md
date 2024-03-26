# Solucion a las Data Races
1. [pthread_mutex_init](#pthread_mutex_init)
2. [pthread_mutex_destroy](#pthread_mutex_destroy),
3. [pthread_mutex_lock](#pthread_mutex_lock),
4. [pthread_mutex_unlock](#pthread_mutex_unlock)

# Nuevas funciones
- Para solucionar los nuevos problemas
nos dejan nuevas funciones dentro de la misma libreria que estamos usando.
 
- Como la variable `pthread_t` tenemos otra que es `pthread_mutex_t`
    - un mutex (diminutivo de exclusion mutua), es un mecanismo de sincronizacion que se utiliza para evitar que dos hilos accedan a la misma parte del codigo a la vez.
    - Cuando un hilo qyuere acceder a una parte de codigo protegida por un mutex debe bloquear el mutex usando la [funcion:`pthread_mutex_lock`](#pthread_mutex_lock) si el mutex ya esta bloqueado por otro hilo , el hilo que intenta bloquear se quedara bloqueado hasta que el mutex este disponible.
        -  Despertar de hilos: Cuando un hilo intenta bloquear un mutex que ya está bloqueado, se pone en un estado de "espera" y se despierta automáticamente cuando el mutex se desbloquea.
    - Una vez que el hilo termina con la seccion del codigo desbloquea el mutex usando la [funcion:`pthread_mutex_unlock`](#pthread_mutex_unlock)
## pthread_mutex_init
- Inicializa el mutex pasado por el primer parametro con `&` y lo deja unlocked.

[subir](#solucion-a-las-data-races)
## pthread_mutex_destroy
- Destruye la memoria inicializada por el init.

[subir](#solucion-a-las-data-races)
## pthread_mutex_lock
- Bloquea el codigo entre lock y unlock si ya estaba bloqueado el hilo se mantiene a la espera.

[subir](#solucion-a-las-data-races)
## pthread_mutex_unlock
- Desbloquea el codigo bloqueado por el mutex lock.
[subir](#solucion-a-las-data-races)

## [Main de ejemplo](srcs/dataraces2.c)
```c
#include "../includes/philo.h"

typedef struct s_data {
    int value;
    pthread_mutex_t lock;
} t_data;

void *sumar(void *arg)
{
    t_data *data = (t_data *)arg;
    int i = 0;
    while (i < 10000000)
    {
        pthread_mutex_lock(&(data->lock));
        data->value = data->value + 1;
        pthread_mutex_unlock(&(data->lock));
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    t_data data;
    data.value = 0;
    pthread_mutex_init(&(data.lock), NULL);

    printf("proyecto Hilos\n");
    pthread_t thread;
    pthread_t thread2;
    if (pthread_create(&thread, NULL, sumar, &data) != 0)
        printf("Error al crear el hilo\n");
    if (pthread_create(&thread2, NULL, sumar, &data) != 0)
        printf("Error al crear el hilo\n");    
    if (pthread_join(thread, NULL) != 0)
        printf("Error al esperar por el hilo\n");
        
    if (pthread_join(thread2, NULL) != 0)
        printf("Error al esperar por el hilo\n");
    printf("el valor de data es %d\n", data.value);

    pthread_mutex_destroy(&(data.lock));

    return (0);
}
```
[subir](#solucion-a-las-data-races)
