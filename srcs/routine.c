/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/29 13:42:18 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"



bool check_die(t_philo *philo)
{
	
	//printf("(%ld) - (%ld) = %ld) >= %ld\n",get_time(),philo->last_eat,get_time()-philo->last_eat,philo->data->time_to_die);
	if ((get_time() - philo->last_eat) >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		pthread_mutex_lock(&philo->data->print);
		printf(RED"%ld %d died\n"RESET,get_time() - philo->data->time,philo->id);
		pthread_mutex_unlock(&philo->data->dead_mutex);
		pthread_mutex_unlock(&philo->data->print);
		return (true);
	}
	return (false);
}
int philo_sleep(t_philo *philo)

{
	printf("%ld %d is sleeping\n",get_time() - philo->data->time,philo->id);
	usleep(philo->data->time_to_sleep );
	return (0);
}

int philo_think(t_philo *philo)
{
	printf("%ld %d is thinking\n",get_time() - philo->data->time,philo->id);
	return (0);
}
int philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	philo->last_eat = get_time();
	philo->eat_count++;
	pthread_mutex_lock(&philo->data->print);
	printf(BLUE"%ld %d is eating\n"RESET,get_time() - philo->data->time,philo->id);
	philo->last_meal_time = get_time();
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->print);
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
		if(check_die(philo) == true)
			return(NULL);
	} 
	
	
	return (NULL);
}