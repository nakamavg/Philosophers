/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/01 21:59:46 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void *check_eat(void *arg)
{
	t_data * data;
	data = (t_philo *)arg;
	int i;
	i = -1;
	
	while(++i < data->num_philo)
	{
		sem_wait(data->eat_semaphore);
	}
	sem_post(data->stop);
	return (NULL);
}

void	*check_die(void *arg)
{
	t_philo * philo;
	philo = (t_philo *)arg;
	
	while (1)
	{
		sem_wait(philo->data->dead_semaphore);
		if (get_time()- philo->last_meal_time >= philo->data->time_to_die && !philo->done_eat)
		{
			print_semaphore_queue(philo, DEAD);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->dead_semaphore);
		 if(philo->data->eat_count_total >= philo->data->num_eat_done && philo->data->num_eat != -1)
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

int philo_eat(t_philo *philo)
{
	print_semaphore_queue(philo, EAT);
	philo->data->eat_count_total++;
	if (philo->eat_count_philo < philo->data->num_eat && philo->data->num_eat != -1)
		philo->eat_count_philo++;
	
	take_action(philo->data->time_to_eat);
	philo->last_meal_time = get_time();

	return (0);
}
