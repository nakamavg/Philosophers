/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:23:13 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 21:24:16 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void ft_error_free(char *str, t_data *data)
{
	if(data->philo)
		free(data->philo);
	if(data->forks)
		free(data->forks);
	ft_error(str);
}