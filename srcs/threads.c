/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:00 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/30 01:09:31 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void init_philo(t_data *data, t_philo *philo)
{
	int i;
	i = -1;
	while (++i < data->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].last_eat =0;
		philo[i].last_meal_time = get_time();
		philo[i].data = data;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->num_philo;
		if (pthread_create(&data->philo[i], NULL, routine, &philo[i]) != 0)
			ft_error_free(ERR_THREAD, data);
	}
	
}
void init_mutex(t_data *data)
{
	int i;
	
	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo); 
	if (!data->forks)
		ft_error_free(ERR_MALLOC, data);
	while (++i < data->num_philo)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	if(pthread_mutex_init(&data->print, NULL) != 0)
		ft_error_free(ERR_MUTEX, data);
	if(pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		ft_error_free(ERR_MUTEX, data);	
	
}

/*
** This function initializes the threads
and the philo struct n times where n is the number of philosophers
and now we have a struct for each philosopher
Need this because i have problems before with the threads and the indexes of the philosophers
*/
void init_threads(t_data *data)
{
	t_philo *philo;
	int i;
	
	i = -1;
	philo = malloc(sizeof(t_philo) * data->num_philo); 
	if (!philo)
		ft_error(ERR_MALLOC);
	data->philo = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->philo)
		ft_error_free(ERR_MALLOC, data);
	memset(philo, 0, sizeof(t_philo) * data->num_philo);
	init_mutex(data);
	data->time = get_time();
	init_philo(data, philo);
	i = -1;
	while (++i < data->num_philo)
		pthread_detach(data->philo[i]);
	check_die(philo);
}
void clear_memory(t_philo *philo)
{
	while(philo->data->num_philo--)
		pthread_mutex_destroy(&philo->data->forks[philo->data->num_philo]);
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->dead_mutex);
	free(philo);
	
} 