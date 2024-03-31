/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:50:21 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 00:56:29 by dgomez-m         ###   ########.fr       */
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
	else if (type == CHECK_DONE_EAT)
		pthread_mutex_lock(&philo->data->check_done_eat);
}

void action_mutex_unlock(t_philo *philo, t_mutex type)
{
	if (type == PRINT)
		pthread_mutex_unlock(&philo->data->print);
	else if (type == DEAD)
		pthread_mutex_unlock(&philo->data->dead_mutex);
	else if (type == EAT)
		pthread_mutex_unlock(&philo->data->eat_mutex);
	else if (type == CHECK_DONE_EAT)
		pthread_mutex_unlock(&philo->data->check_done_eat);
}
void action_mutex_init(t_data *data, t_mutex type)
{
	if (type == PRINT)
	{	
		if(pthread_mutex_init(&data->print, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == DEAD)
	{
	
		if(pthread_mutex_init(&data->dead_mutex, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == EAT)
	{	
		if(pthread_mutex_init(&data->eat_mutex, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
	else if (type == CHECK_DONE_EAT)
	{	
		if(pthread_mutex_init(&data->check_done_eat, NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	}
}

void action_mutex_destroy(t_philo *philo, t_mutex type)
{
	if (type == PRINT)
		pthread_mutex_destroy(&philo->data->print);
	else if (type == DEAD)
		pthread_mutex_destroy(&philo->data->dead_mutex);
	else if (type == EAT)
		pthread_mutex_destroy(&philo->data->eat_mutex);
	else if (type == CHECK_DONE_EAT)
		pthread_mutex_destroy(&philo->data->check_done_eat);
}

