/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:32:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/06 04:59:48 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdbool.h>

bool check_death(t_philo *philo)
{
    int i;
    long int time;

    i = -1;
    while (++i < philo->data->num_philo && !philo->data->dead)
    {
        pthread_mutex_lock(&philo[i].data->eat_count_mutex);
        time = get_time() - philo[i].last_meal_time;
        pthread_mutex_unlock(&philo[i].data->eat_count_mutex);

        pthread_mutex_lock(&philo[i].data->dead_mutex);
        if (time > philo->data->time_to_die && !philo[i].done_eat)
        {
            philo[i].data->idx_of_dead = philo[i].id;
            philo->time_of_death = get_time();
            philo->data->dead = true;
            pthread_mutex_unlock(&philo[i].data->dead_mutex);
            return (true);
        }
        pthread_mutex_unlock(&philo[i].data->dead_mutex);
		usleep(100);
    }
    return (false);
}

bool	check_all_eaten(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philo && !philo->data->dead)
	{
		pthread_mutex_lock(&philo[i].data->eat_count_mutex);
		if (!philo[i].done_eat)
		{
			pthread_mutex_unlock(&philo[i].data->eat_count_mutex);
				return (false);
		}
		pthread_mutex_unlock(&philo[i].data->eat_count_mutex);
	}
	return (true);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->dead == false)
	{
		if (check_death(philo))
			break ;
		if (check_all_eaten(philo))
		{
			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->all_eaten = true;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			break ;
		}
	}
	return (NULL);
}
