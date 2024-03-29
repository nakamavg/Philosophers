/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:20 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/29 11:52:12 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
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
# define MS_TO_MICRO 1000
# define MICRO_MIN 60000
# define TIME_LESS_MIN "Error: time less than 60ms\n"

typedef struct s_data
{
	int				num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				num_eat;
	bool			dead;
	long int		time;
	pthread_t		*philo;
	pthread_t		dead_thread;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long int		last_eat;
	long int		last_meal_time;
	struct s_data	*data;
}					t_philo;

// threads.c
void				init_threads(t_data *data);
void				clear_memory(t_philo *philo);
// utils.c
void				ft_error(char *str);
bool				ft_isdigit(char c);
int					ft_strlen(char *str);
long int			ft_atol(const char *str);
long int			get_time(void);
// utils2.c
void				ft_error_free(char *str, t_data *data);
void				check_time(long int time);
// routines.c
void				*routine(void *arg);
bool				check_die(t_philo *philo);

#endif