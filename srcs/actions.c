/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/30 21:48:51 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	philo_dead(t_philo *philo)
{
	long int	diff_time;

	diff_time = get_time() - philo->last_meal_time;
	if (diff_time == philo->data->time_to_die && !philo->done_eat)
	{
		pthread_mutex_lock(&philo->data->print);
		pthread_mutex_lock(&philo->data->dead_mutex);
		printf(RED "%ld %d died\n" RESET, get_time() - philo->data->time,
			philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (true);
	}
	return (false);
}

void	check_die(t_philo *philo)
{
	int	i;

	while (42)
	{
		if(philo->data->num_eat_done == philo->data->num_philo)
		{
			exit(EXIT_SUCCESS);
			break;
		}
		i = -1;
		while (++i < philo->data->num_philo)
		{
			if (philo_dead(&philo[i]))
				ft_finish(philo->data);
		
		}
	}
}

int	philo_sleep(t_philo *philo)
{
	take_action(philo->data->time_to_sleep);
	print_mutex(philo, BLUE "is sleeping" RESET);
	return (0);
}

int	philo_think(t_philo *philo)
{
	print_mutex(philo, GREEN "is thinking" RESET);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	if(philo->done_eat)
		{
			print_mutex(philo, VIOLET"is done eating" RESET);
			return (1);
		}
	lock_forks(philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	if(philo->eat_count == philo->data->num_eat)
		philo->data->num_eat_done++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	take_action(philo->data->time_to_eat);
	print_mutex(philo,VIOLET"is eating" RESET);
	philo->eat_count++;
	if(philo->eat_count == philo->data->num_eat)
		philo->done_eat = true;
	philo->last_meal_time = get_time();
	
	unlock_forks(philo);
	return (0);
}
