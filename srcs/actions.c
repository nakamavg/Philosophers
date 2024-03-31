/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 04:12:14 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	philo_dead(t_philo *philo)
{
	if (get_time() - philo->last_meal_time > philo->data->time_to_die && !philo->done_eat)
	{
		action_mutex_lock(philo, DEAD);
		print_mutex(philo, RED "died" RESET);
		action_mutex_unlock(philo, DEAD);
		return (true);
	}
	return (false);
}

int	check_die(t_philo *philo)
{
	if (philo_dead(philo))
		return (1);
	return (0);
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
	action_mutex_lock(philo, EAT);
	if(philo->eat_count == philo->data->num_eat)
		philo->data->num_eat_done++;
	if(philo->eat_count == philo->data->num_eat)
		philo->done_eat = true;
	philo->eat_count++;
	philo->last_meal_time = get_time();
	action_mutex_unlock(philo, EAT);
	take_action(philo->data->time_to_eat);
	print_mutex(philo,VIOLET"is eating" RESET);
	
	unlock_forks(philo);
	return (0);
}
