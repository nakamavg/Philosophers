/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/30 02:54:59 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	philo_dead(t_philo *philo)
{
	long int	diff_time;

	diff_time = get_time() - philo->last_meal_time;
	if (diff_time == philo->data->time_to_die)
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
		i = -1;
		while (++i < philo->data->num_philo)
		{
			if (philo_dead(&philo[i]))
				ft_finish(philo->data);
			usleep(100);
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
	lock_forks(philo);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_meal_time = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	take_action(philo->data->time_to_eat);
	print_mutex(philo, YELLOW "is eating" RESET);
	unlock_forks(philo);
	return (0);
}
