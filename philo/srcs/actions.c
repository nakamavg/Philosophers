/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/06 04:56:52 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool check_bool(pthread_mutex_t *mutex, bool *dead)
{
	bool ret;
	pthread_mutex_lock(mutex);
	if (*dead)
		ret = true;
	else
		ret = false;
	pthread_mutex_unlock(mutex);
	return (ret);
}

bool	philo_sleep(t_philo *philo)
{
	if(check_bool(&philo->data->dead_mutex, &philo->data->dead))
		return (1);
	take_action(philo->data->time_to_sleep);
	print_mutex(philo, BLUE "is sleeping" RESET);
	return (0);
}

bool	philo_think(t_philo *philo)
{
	if(check_bool(&philo->data->dead_mutex, &philo->data->dead))
		return (1);
	print_mutex(philo, GREEN "is thinking" RESET);
	return (0);
}
int	philo_eat(t_philo *philo)
{
	while (!check_bool(&philo->data->dead_mutex, &philo->data->dead) && 
	!check_bool(&philo->data->eat_count_mutex, &philo->done_eat))
	{
		lock_forks(philo);
		action_mutex_lock(philo, EAT);
		if (philo->eat_count == philo->data->max_eat &&
		 philo->data->max_eat != -1)
		{
			pthread_mutex_lock(&philo->data->eat_count_mutex);
			philo->done_eat = true;
			pthread_mutex_unlock(&philo->data->eat_count_mutex);
		}
		if(philo->data->max_eat != -1)
			philo->eat_count++;
		action_mutex_unlock(philo, EAT);
		print_mutex(philo, VIOLET "is eating" RESET);
		take_action(philo->data->time_to_eat);
		pthread_mutex_lock(&philo->data->eat_count_mutex);
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&philo->data->eat_count_mutex);
		unlock_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
		return (1);
}


