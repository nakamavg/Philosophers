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
[subir](#solucion-a-las-data-races)
## pthread_mutex_destroy
[subir](#solucion-a-las-data-races)
## pthread_mutex_lock
[subir](#solucion-a-las-data-races)
## pthread_mutex_unlock
[subir](#solucion-a-las-data-races)
