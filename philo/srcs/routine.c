/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/08 07:54:25 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	one_fillo_route(t_philo *philo)
{
	print_mutex(philo, YELLOW "has taken a fork" RESET);
	while (1)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->dead_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
}

static bool	are_id_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (true);
	return (false);
}

static int	philo_routine(t_philo *philo)
{
	if (philo->data->num_philo == 1)
		if (one_fillo_route(philo) == 1)
			return (1);
	if (are_id_even(philo))
		usleep(100);
	if (philo_eat(philo) == 1)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->dead)
	{
		if (philo->done_eat)
			return (NULL);
		if (philo_routine(philo) == 1)
			break ;
	}
	return (NULL);
}
