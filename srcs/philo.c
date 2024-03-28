/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:53:35 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/28 01:44:03 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void assing_data(int ac, char **av, t_data *data)
{ 
	data->num_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) *1000;
	if (ac == 6)
		data->num_eat = ft_atol(av[5]);
	
}
void	check_args(int ac, char **av, t_data *data)
{
	int	i;
	int j;
	
	i = 0;
	
	if (ac < 5 || ac > 6)
		ft_error(IVALID_ARGS);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_isdigit(av[i][j]) == false)
				ft_error(IVALID_CHARS);
		}
	}
	memset(data, 0, sizeof(t_data));
	assing_data(ac, av, data);
	
	
}
int	main(int ac, char **av)
{
	t_data data;
	check_args(ac, av, &data);
	init_threads(&data);
	//clear_memory(&philo);
	
	
	return (0);
}