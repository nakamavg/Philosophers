/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:53:35 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 21:19:04 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


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
	
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_eat = ft_atoi(av[5]);
}
int	main(int ac, char **av)
{
	t_data data;
	check_args(ac, av, &data);
	init_threads(&data);
	//clear_memory(&philo);
	
	
	return (0);
}