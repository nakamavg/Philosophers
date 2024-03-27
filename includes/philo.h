/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:20 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/27 13:55:17 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# define IVALID_ARGS "Error: invalid number of arguments\n"
# define IVALID_CHARS "Error: invalid characters in arguments\n"
# define NMBR_NEGATIVE "Error: negative number\n"
# define NMBR_OVERFLOW "Error: number overflow\n"
# define ERR_MALLOC "Error: malloc\n"
# define ERR_THREAD "Error: pthread_create\n"


typedef struct s_philo
{
	int num_philo;
	pthread_t *philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_eat;
}	t_philo;

//threads.c
void init_threads(t_philo *philo);
// utils.c
void	ft_error(char *str);
bool	ft_isdigit(char c);
int ft_strlen(char *str);
int	ft_atoi(const char *str);
//routines.c
void *routine(void *arg);


#endif