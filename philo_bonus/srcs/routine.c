/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 00:34:49 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void *check_eat(void *arg)
{
	t_data * data;
	data = (t_data *)arg;
	int i;
	i = -1;
	
	if (data->num_eat == -1)
		return (NULL);
	while(++i < data->num_philo)
	{
		sem_wait(data->eat_semaphore);
	}
	printf("%sAll philosophers have eaten %d times%s\n", GREEN, data->num_eat, RESET);
	sem_post(data->stop);
	return (NULL);
}

void	routine(t_philo *philo)
{
	pthread_t   dead_monitor;

    pthread_create(&dead_monitor, NULL, check_die, philo);
    pthread_detach(dead_monitor);
	while (42)
    {
		if (philo->data->num_eat != -1 && philo->eat_count_philo >= philo->data->num_eat)
		{
			sem_post(philo->data->eat_semaphore);
			break ;
		}
		lock_forks(philo);
		philo_eat(philo);
        unlock_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
    }
	exit(0);
}
