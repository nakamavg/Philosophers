/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:07:37 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/30 02:47:10 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	printf(RED "%s\n", str);
	exit(EXIT_FAILURE);
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

long int	ft_atol(const char *str)
{
	unsigned long int	nbr;

	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 45)
		ft_error(NMBR_NEGATIVE);
	if (*str == 43)
		str++;
	nbr = 0;
	while (*str && *str > 47 && *str < 58)
		nbr = nbr * 10 + *str++ - 48;
	if (nbr < 1 || nbr > 2147483647)
		ft_error(NMBR_OVERFLOW);
	return (nbr);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
