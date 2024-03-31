/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:50:21 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 08:46:55 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	action_sem_lock(t_philo *philo, t_semaphore type)
{
	if (type == PRINT)
	{
		if (sem_wait(philo->data->print) == -1)
			ft_error_free(ERR_SEMAPHORE_WAIT, philo->data);
	}
	else if (type == DEAD)
	{
		if (sem_wait(philo->data->dead_semaphore) == -1)
			ft_error_free(ERR_SEMAPHORE_WAIT, philo->data);
	}
	else if (type == EAT)
	{
		if (sem_wait(philo->data->eat_semaphore) == -1)
			ft_error_free(ERR_SEMAPHORE_WAIT, philo->data);
	}
	else if (type == FORK)
	{
		if (sem_wait(philo->data->forks) == -1)
			ft_error_free(ERR_SEMAPHORE_WAIT, philo->data);
	}
}

void	action_sem_unlock(t_philo *philo, t_semaphore type)
{
	if (type == PRINT)
	{
		if (sem_post(philo->data->print) == -1)
			ft_error_free(ERR_SEMAPHORE_POST, philo->data);
	}
	else if (type == DEAD)
	{
		if (sem_post(philo->data->dead_semaphore) == -1)
			ft_error_free(ERR_SEMAPHORE_POST, philo->data);
	}
	else if (type == EAT)
	{
		if (sem_post(philo->data->eat_semaphore) == -1)
			ft_error_free(ERR_SEMAPHORE_POST, philo->data);
	}
	else if (type == FORK)
	{
		if (sem_post(philo->data->forks) == -1)
			ft_error_free(ERR_SEMAPHORE_POST, philo->data);
	}
}

void	action_sem_init(t_data *data, t_semaphore type)
{
	if (type == PRINT)
	{
		data->print = sem_open("/print", O_CREAT, 0644, 1);
		if (data->print == SEM_FAILED)
			ft_error_free(ERR_SEMAPHORE, data);
	}
	else if (type == DEAD)
	{
		data->dead_semaphore = sem_open("/dead", O_CREAT, 0644, 1);
		if (data->dead_semaphore == SEM_FAILED)
			ft_error_free(ERR_SEMAPHORE, data);
	}
	else if (type == EAT)
	{
		data->eat_semaphore = sem_open("/eat", O_CREAT, 0644, 1);
		if (data->eat_semaphore == SEM_FAILED)
			ft_error_free(ERR_SEMAPHORE, data);
	}
	else if (type == FORK)
	{
		data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philo);
		if (data->forks == SEM_FAILED)
			ft_error_free(ERR_SEMAPHORE, data);
	}
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
