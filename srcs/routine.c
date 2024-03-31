/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 03:39:04 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
bool aux_done_eat(t_philo *philo)
{
	action_mutex_lock(philo, CHECK_DONE_EAT);
	if (philo->data->num_eat != -1 && philo->eat_count == philo->data->num_eat)
	{
		action_mutex_unlock(philo, CHECK_DONE_EAT);
		return (true);
	}
	action_mutex_unlock(philo, CHECK_DONE_EAT);
	return (false);
}

static bool are_id_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (true);
	return (false);
}
static int philo_routine(t_philo *philo)
{
    if (are_id_even(philo))
    {
        if (philo_eat(philo) == 1)
            return (1);
        if (philo_sleep(philo))
            return (1);
        if (philo_think(philo))
            return (1);
    }
    else 
    {
        if (philo_sleep(philo))
            return (1);
        if (philo_think(philo))
            return (1);
        if (philo_eat(philo) == 1)
            return (1);
    }
    return (0);
}


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->done_eat)
	{
		if(philo->done_eat)
			return (NULL) ;
		if (philo_routine(philo) == 1)
			break ;
	}
	return (NULL);
}
