/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:22:05 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 00:58:58 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	lock_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_semaphore_queue(philo, FORK);
	sem_wait(philo->data->forks);
	print_semaphore_queue(philo, FORK);
}

void	unlock_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
