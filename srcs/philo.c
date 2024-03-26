/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:53:35 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 00:41:34 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	check_args(int ac, char **av, t_philo *philo)
{
	int	i;
	int j;
	
	i = 1;
	
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
	memset(philo, 0, sizeof(t_philo));
	philo->num_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->num_eat = ft_atoi(av[5]);
}
int	main(int ac, char **av)
{
	t_philo	philo;
	check_args(ac, av, &philo);
	
	
	return (0);
}