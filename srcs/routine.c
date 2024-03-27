/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 21:46:21 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

int philo_sleep(t_philo *philo)

{
	printf("%d is sleeping\n", philo->id);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int philo_think(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
	return (0);
}
int philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	printf("%d is eating\n", philo->id);
	philo->last_eat = get_time();
	philo->last_meal_time = philo->last_eat;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	philo->eat_count++;
	if (philo->eat_count == philo->data->num_eat)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->eat_count++;
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
	
	
	return (0);
}

void *routine(void *arg)
{
	 t_philo *philo;
	philo = (t_philo *)arg;

	while(42)
	{
		if(philo_eat(philo) == 1)
			break;
		if(philo_sleep(philo) == 1)
			break;
		if(philo_think(philo) == 1)
			break; 
	} 
	
	
	return (NULL);
}