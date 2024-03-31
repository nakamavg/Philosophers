/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:23:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 05:55:11 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	diff_time(long int time)
{
	return (get_time() - time);
}

void	ft_error_free(char *str, t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	ft_error(str);
}

void	take_action(long int time)
{
	long int	start;

	start = get_time();
	while (42)
	{
		if (diff_time(start) >= time)
			break ;
		usleep(100);
	}
}

void	print_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
