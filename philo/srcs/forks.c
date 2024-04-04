/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:22:05 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 03:03:00 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_mutex(philo, YELLOW "has taken a fork" RESET);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_mutex(philo, YELLOW "has taken a fork" RESET);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_mutex(philo, YELLOW "has taken a fork" RESET);
		print_mutex(philo, YELLOW "has taken a fork" RESET);
	}
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	if (philo->data->num_philo > 1)
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}
