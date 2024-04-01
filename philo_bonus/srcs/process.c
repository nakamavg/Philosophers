/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:00 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 00:26:36 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"


static void	init_philo(t_data *data, t_philo *philo)
{
    int	i;

    i = 0;
    while (i < data->num_philo)
    {
		philo[i].data = data;
        data->pid[i] = fork();
        if (data->pid[i] == 0)
        {
        	philo[i].id = i + 1;
            philo[i].last_meal_time = get_time();
			philo[i].done_eat = false;
			philo[i].eat_count_philo = 0;
			philo[i].n_eat = data->num_eat;
            routine(&philo[i]);
			exit(0);
        }
		usleep(100);
        i++;
    }
}

void	init_semaphores(t_data *data)
{
	action_sem_init(data, PRINT);
	action_sem_init(data, DEAD);
	action_sem_init(data, EAT);
	action_sem_init(data, FORK);
	action_sem_init(data, STOP);
	
}

void	init_processes(t_data *data)
{
	t_philo	*philo;
	pthread_t	eat_monitor;
	
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		ft_error(ERR_MALLOC);
	data->pid = malloc(sizeof(pid_t) * data->num_philo);
	if (data->pid == NULL)
		ft_error(ERR_MALLOC);
	memset(philo, 0, sizeof(t_philo) * data->num_philo);
	init_semaphores(data);
	data->time = get_time();
	sem_wait(data->stop);
	pthread_create(&eat_monitor, NULL, check_eat, data);
	pthread_detach(eat_monitor);
	init_philo(data, philo);
	
	sem_wait(data->stop);
	
	clear_memory(philo);
}
