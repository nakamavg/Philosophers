/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:58:00 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 13:53:28 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_threads(t_philo *philo)
{
	int i; 
	
	i = -1;
	philo->philo = malloc(sizeof(pthread_t) * philo->num_philo);
	if (!philo->philo)
		ft_error(ERR_MALLOC);
	while (++i < philo->num_philo)
	{
		if (pthread_create(&philo->philo[i], NULL, &routine,&philo[i]) != 0)
			ft_error(ERR_THREAD);
	}
	i = -1;
	while (++i < philo->num_philo)
		if (pthread_join(philo->philo[i], NULL) != 0)
			ft_error(ERR_THREAD);			
}
