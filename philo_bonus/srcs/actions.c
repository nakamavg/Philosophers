/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/08 06:46:22 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*check_die(void *arg)
{
	t_philo	*philo;
	long long time;
	
	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->dead_semaphore);
		sem_wait(philo->data->eat_count);
		time = get_time() - philo->last_meal_time;
		sem_post(philo->data->eat_count);
		if (time > philo->data->time_to_die)
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
	sem_wait(philo->data->eat_count);
	philo->eat_count_philo++;
	sem_post(philo->data->eat_count);
	take_action(philo->data->time_to_eat);
	sem_wait(philo->data->eat_count);
	philo->last_meal_time = get_time();
	sem_post(philo->data->eat_count);
	return (0);
}
