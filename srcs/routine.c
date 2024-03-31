/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 04:19:43 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
