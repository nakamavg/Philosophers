/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:00 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 08:53:56 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	init_philo(t_data *data, t_philo *philo)
{
	int	i;
	
	i = -1;
	while (++i < data->num_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			ft_error(ERR_PROCESS);
		if (data->pid[i] == 0)
		{
			philo[i].id = i + 1;
			philo[i].done_eat = false;
			philo[i].eat_count = 0;
			philo[i].last_meal_time = get_time();
			philo[i].data = data;
			
		}
	}
}

void init_semaphores(t_philo *philo)
{
	int i ;
	
	i = -1;
	action_sem_init(philo->data, PRINT);
	action_sem_init(philo->data, DEAD);
	action_sem_init(philo->data, EAT);
	while (++i < philo->data->num_philo)
	{
		action_sem_init(philo->data, FORK);

}

void	init_processes(t_data *data);
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		ft_error(ERR_MALLOC);
	data->philo = malloc(sizeof(pid_t) * data->num_philo);
	if (!data->philo)
		ft_error(ERR_MALLOC);
	init_philo(data, philo);
	init_semaphores(philo);
}

