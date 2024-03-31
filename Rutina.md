# COMER DORMIR PENSAR REPETIR

- Depende que hilo seas si par o impar
- Haras comer dormir pensar o dormir pensar comer
## Pensar y dormir facil

- Funcion dormir un printf protegido por mutex para que solo se pueda imprimir una cosa a la vez, por si algun hilo loco se quiere meter.
- y Take action que nos hace un usleep por el tiempo que nos han metido por argumentos del programa a dormir

- Pensar solo imprime estoy pensando pero en realidad no piensa nada

## la chicha comer un buen pulpo 

- Bloqueamos los tenedores con un mutex
	- calculamos si estamos en un filo con id par o impar para coger primero un tenedor o el otro	
- Bloqueo de comer para proteger de data races
	- Dentro de este mutex:
	- comprobamos si esta lleno(ha comido todas sus comidas en el caso de que nos lo pasen)
	- sumamos comida 
	- obtenemos el tiempo que se ha hecho esta comida, para luego calcular si debe morir.
	- salimos del mutex EAT
- Usleep de el tiempo de comer
- imprimimos que ha comido
- y desbloqueamos tenedores

## La funcion dead
Esto no es un hilo y gracias al detach esta en un loop infinito comprobando en cuanto devuelve true terminamos ejecución
 - Calcula el tiempo desde que comimos la ultima vez es mayor a el tiempo que nos han pasado que tiene a comer si es asi bloqueamos el mutex de muerte , imprimimos muerte
 desbloqueamos y nos vamos.

 Gracias por leer dejo foto y me piro
 ![Alt text](<CleanShot 2024-03-31 at 06.08.06@2x.png>)