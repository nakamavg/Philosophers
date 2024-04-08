/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:50:21 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/08 06:56:23 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	create_semaphore(const char *name, sem_t **sem, int value, t_data *data)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0644, value);
	if (*sem == SEM_FAILED)
		ft_error_free(ERR_SEMAPHORE, data);
}

void	action_sem_init(t_data *data, t_semaphore type)
{
	if (type == PRINT)
		create_semaphore("/print", &(data->print), 1, data);
	else if (type == DEAD)
		create_semaphore("/dead", &(data->dead_semaphore), 1, data);
	else if (type == EAT)
		create_semaphore("/eat", &(data->eat_semaphore), 1, data);
	else if (type == FORK)
		create_semaphore("/forks", &(data->forks), data->num_philo, data);
	else if (type == STOP)
		create_semaphore("/stop", &(data->stop), 1, data);
	else if (type == EAT_COUNT)
		create_semaphore("/eat_count", &(data->eat_count), 1, data);
}

void	clear_memory(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = philo->data;
	i = -1;
	while (++i < philo->data->num_philo)
		kill(data->pid[i], SIGKILL); 
	sem_close(philo->data->dead_semaphore);
	sem_close(philo->data->eat_semaphore);
	sem_close(philo->data->eat_count);
	sem_close(philo->data->stop);
	sem_close(philo->data->print);
	sem_close(philo->data->forks);
	free(philo->data->pid);
	
	free(philo);
}
