/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataraces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:37:48 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/26 21:30:15 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *sumar(void *arg)
{
    int *data = (int *)arg;
    int i = 0;
    while (i < 1000000)
    {
        *data = *data + 1;
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int data = 0;

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
    printf("el valor de data es %d\n", data);
    return (0);
}