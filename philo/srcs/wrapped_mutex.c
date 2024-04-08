/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:50:21 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/08 08:09:09 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	action_mutex_lock(t_philo *philo, t_mutex type)
{
	if (type == PRINT)
		pthread_mutex_lock(&philo->data->print);
	else if (type == DEAD)
		pthread_mutex_lock(&philo->data->dead_mutex);
	else if (type == EAT)
		pthread_mutex_lock(&philo->data->eat_mutex);
	else if (type == EAT_COUNT)
		pthread_mutex_lock(&philo->data->eat_count_mutex);
}

void	action_mutex_unlock(t_philo *philo, t_mutex type)
{
	if (type == PRINT)
		pthread_mutex_unlock(&philo->data->print);
	else if (type == DEAD)
		pthread_mutex_unlock(&philo->data->dead_mutex);
	else if (type == EAT)
		pthread_mutex_unlock(&philo->data->eat_mutex);
	else if (type == EAT_COUNT)
		pthread_mutex_unlock(&philo->data->eat_count_mutex);
}

void	action_mutex_init(t_data *data, t_mutex type)
{
	if (type == PRINT)
	{
		if (pthread_mutex_init(&data->print, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == DEAD)
	{
		if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == EAT)
	{
		if (pthread_mutex_init(&data->eat_mutex, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == EAT_COUNT)
	{
		if (pthread_mutex_init(&data->eat_count_mutex, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
}

void	action_mutex_destroy(t_philo *philo, t_mutex type)
{
	if (type == PRINT)
		pthread_mutex_destroy(&philo->data->print);
	else if (type == DEAD)
		pthread_mutex_destroy(&philo->data->dead_mutex);
	else if (type == EAT)
		pthread_mutex_destroy(&philo->data->eat_mutex);
	else if (type == EAT_COUNT)
		pthread_mutex_destroy(&philo->data->eat_count_mutex);
}
