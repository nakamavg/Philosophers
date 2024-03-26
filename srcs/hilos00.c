/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:37:48 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/26 20:57:32 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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