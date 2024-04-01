/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:33:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/01 21:56:04 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	routine(t_philo *philo)
{
	pthread_t   dead_monitor;

    pthread_create(&dead_monitor, NULL, check_die, philo);
    pthread_detach(dead_monitor);
	while (42)
    {
		lock_forks(philo);
		philo_eat(philo);
        unlock_forks(philo);
		philo_sleep(philo);
		philo_think(philo);

    }
}
