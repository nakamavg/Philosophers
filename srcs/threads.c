/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:00 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 04:09:20 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].done_eat = false;
		philo[i].eat_count = 0;
		philo[i].last_eat = 0;
		philo[i].last_meal_time = get_time();
		philo[i].data = data;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->num_philo;
		if (pthread_create(&data->philo[i], NULL, routine, &philo[i]) != 0)
			ft_error_free(ERR_THREAD, data);
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		ft_error_free(ERR_MALLOC, data);
	while (++i < data->num_philo)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			ft_error_free(ERR_MUTEX, data);
	action_mutex_init(data, PRINT);
	action_mutex_init(data, DEAD);
	action_mutex_init(data, EAT);
	action_mutex_init(data, CHECK_DONE_EAT);
	
}

void	init_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

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
	while(42)
	{	
		if(philo->done_eat)
			break ;
		if(check_die(philo) == 1)
			break ;
		
	}
	
	clear_memory(philo);
}

void	clear_memory(t_philo *philo)
{
	while (philo->data->num_philo--)
		pthread_mutex_destroy(&philo->data->forks[philo->data->num_philo]);
	action_mutex_destroy(philo,PRINT);
	action_mutex_destroy(philo, DEAD);
	action_mutex_destroy(philo, EAT);
	action_mutex_destroy(philo, CHECK_DONE_EAT);
	free(philo->data->forks);

	free(philo);
	printf("Memory cleared\n");
}
