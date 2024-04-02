# LOS FILOSOFOS BONUS
## Estamos a punto de aprender el maravilloso mundo de los semaforos
### Enlace a Readme explicando las funciones nuevas [aqui](funcionessemaforos.md)

# Ahora podemos usar Los hilos del Filosofo normal sin mutex
# Semaforos
# Y Procesos

- Como dice el Subject , cada proceso va a ser un filosofo 

- Como ahora los tenedores estan el centro el semaforo va hacer de tenedor, tambien tendremos semaforos para todas las partes importantes del codigo , un semaforo cada vez que voy a hacer un printf
Para que no pueden escribir todos los filos a la vez, un semaforo en dead, para que no puedan morir mas de uno y usare un par de semaforos especiales.

- Mientras los procesos se ejecutan he pueso un sem_wait para que el proceso padre (que no es un filosofo como pide el subject)
se quede esperando, no hay waitpid permitido aqui.

- Es importante que por cada proceso tengas cuidado en como se duplican las variables en el hijo y como asignas el tiempo despues del fork

- Justamente despues del fork - tengo n hilos por cada proceso para checkear la muerte y tengo un hilo para saber si en el caso de que nos pasan numero de comidas bloquear n veces  el hilo 
por cada proceso/filosofo que haya terminado de comer pasara por un post.
