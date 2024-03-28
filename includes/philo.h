/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:20 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/28 01:58:51 by dgomez-m         ###   ########.fr       */
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
# define ERR_MUTEX "Error: pthread_mutex_init\n"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define RED "\033[0;31m"

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	int				dead;
	long int		time;
	pthread_t		*philo;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long int		last_eat;
	int				last_meal_time;
	struct s_data	*data;
}	t_philo;

//threads.c
void init_threads(t_data *data);
void clear_memory(t_philo *philo);
// utils.c
void	ft_error(char *str);
bool	ft_isdigit(char c);
int ft_strlen(char *str);
long int	ft_atol(const char *str);
long int	get_time(void);
//utils2.c
void ft_error_free(char *str, t_data *data);
//routines.c
void *routine(void *arg);


#endif