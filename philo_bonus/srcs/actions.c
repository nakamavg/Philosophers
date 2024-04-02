/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 02:06:20 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*check_die(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->dead_semaphore);
		if (get_time() - philo->last_meal_time >= philo->data->time_to_die)
		{
			print_semaphore_queue(philo, DEAD);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->dead_semaphore);
		if (philo->data->eat_count_total >= philo->data->num_eat_done
			&& philo->data->num_eat != -1)
		{
			sem_post(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

int	philo_sleep(t_philo *philo)
{
	take_action(philo->data->time_to_sleep);
	print_semaphore_queue(philo, SLEEP);
	return (0);
}

int	philo_think(t_philo *philo)
{
	print_semaphore_queue(philo, THINK);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	print_semaphore_queue(philo, EAT);
	philo->eat_count_philo++;
	take_action(philo->data->time_to_eat);
	philo->last_meal_time = get_time();
	return (0);
}
