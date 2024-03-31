/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:20 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/31 06:04:17 by dgomez-m         ###   ########.fr       */
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
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define VIOLET "\033[0;35m"
# define MICRO_MIN 60
# define TIME_LESS_MIN "Error: time less than 60ms\n"

typedef enum e_mutex
{
	PRINT,
	DEAD,
	EAT,
	EAT_COUNT,
	CHECK_DONE_EAT
}					t_mutex;

typedef struct s_data
{
	int				num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				num_eat;
	long int		time;
	int				num_eat_done;
	pthread_t		*philo;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	eat_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	bool			done_eat;
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
void				take_action(long int time);
void				ft_finish(t_data *data);
long int			diff_time(long int time);
void				print_mutex(t_philo *philo, char *str);
// routines.c
void				*routine(void *arg);
void				*one_fillo_route(void *arg);
bool				aux_done_eat(t_philo *philo);

// actions.c
bool				philo_dead(t_philo *philo);
bool					check_die(t_philo *philo);
int					philo_sleep(t_philo *philo);
int					philo_think(t_philo *philo);
int					philo_eat(t_philo *philo);
// forks.c
void				lock_forks(t_philo *philo);
void				unlock_forks(t_philo *philo);
// wrapped_mutex.c
void				action_mutex_lock(t_philo *philo, t_mutex type);
void				action_mutex_unlock(t_philo *philo, t_mutex type);
void				action_mutex_init(t_data *data, t_mutex type);
void				action_mutex_destroy(t_philo *philo, t_mutex type);

#endif