/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:50:21 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/02 00:28:24 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void create_semaphore(const char *name, sem_t **sem, int value, t_data *data)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0644, value);
	if (*sem == SEM_FAILED)
		ft_error_free(ERR_SEMAPHORE, data);
}

void open_semaphore(const char *name, sem_t **sem, t_data *data)
{
	*sem = sem_open(name, O_CREAT, 0644, 1);
	if (*sem == SEM_FAILED)
		ft_error_free(ERR_SEMAPHORE, data);
}

void action_sem_init(t_data *data, t_semaphore type)
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
}
	

void	action_sem_destroy(t_data *data)
{
	if (sem_close(data->print) == -1)
		ft_error_free(ERR_SEMAPHORE_CLOSE, data);
	if (sem_close(data->dead_semaphore) == -1)
		ft_error_free(ERR_SEMAPHORE_CLOSE, data);
	if (sem_close(data->eat_semaphore) == -1)
		ft_error_free(ERR_SEMAPHORE_CLOSE, data);
	if (sem_unlink("/print") == -1)
		ft_error_free(ERR_SEMAPHORE_UNLINK, data);
	if (sem_unlink("/dead") == -1)
		ft_error_free(ERR_SEMAPHORE_UNLINK, data);
	if (sem_unlink("/eat") == -1)
		ft_error_free(ERR_SEMAPHORE_UNLINK, data);
}
