/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataraces2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:37:48 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/26 23:32:08 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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