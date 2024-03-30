/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/30 02:50:29 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (42)
	{
		if (philo_eat(philo) == 1)
			break ;
		if (philo_sleep(philo) == 1)
			break ;
		if (philo_think(philo) == 1)
			break ;
		if (philo->data->num_eat != -1
			&& philo->eat_count >= philo->data->num_eat)
			break ;
	}
	return (NULL);
}
