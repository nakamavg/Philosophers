/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:23:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/01 21:36:28 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long int	diff_time(long int time)
{
	return (get_time() - time);
}

void	ft_error_free(char *str, t_data *data)
{
	ft_error(str);
	if (data->pid)
		free(data->pid);
	if (data->forks)
		free(data->forks);
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

void print_semaphore_queue(t_philo *philo ,t_semaphore action)
{
	sem_wait(philo->data->print);
	if (action == EAT)
	{
		printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, VIOLET"is eating" RESET);
	}
	else if (action == SLEEP)
	{
		printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, BLUE"is sleeping" RESET);
	}
	else if (action == THINK)
	{
		printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, GREEN"is thinking" RESET);
	}
	else if (action == FORK)
	{
		printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, YELLOW"has taken a fork" RESET);
	}
	sem_post(philo->data->print);
	if (action == DEAD)
	{
		sem_wait(philo->data->print);
		printf("%ld %d %s\n", diff_time(philo->data->time), philo->id, RED"died" RESET);
	}
}
void clear_memory(t_philo *philo)
{
	t_data *data;
	data = philo->data;
	int i;
	
	i = -1;
 	while (++i < philo->data->num_philo)
		kill(data->pid[i], SIGKILL);
	sem_close(philo->data->dead_semaphore);
	sem_close(philo->data->eat_semaphore);
	sem_close(philo->data->stop);
	sem_close(philo->data->print);
	sem_close(philo->data->forks);
	free(philo);
}

