/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:44:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 13:58:36 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;
	static int i = 0;
	philo = (t_philo *)arg;
	printf("hilo %d\n", ++i);
	
	(void)philo;
	return (NULL);
}