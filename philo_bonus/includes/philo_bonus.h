/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:24:20 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/04/01 21:49:18 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
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
# define ERR_PROCESS "Error: fork\n"
# define ERR_SEMAPHORE_INIT "Error: semaphore init\n"
# define ERR_SEMAPHORE_CLOSE "Error: semaphore close\n"
# define ERR_SEMAPHORE_UNLINK "Error: semaphore unlink\n"
# define ERR_SEMAPHORE_WAIT "Error: semaphore wait\n"
# define ERR_SEMAPHORE_POST "Error: semaphore post\n"
# define ERR_SEMAPHORE_DESTROY "Error: semaphore destroy\n"
# define ERR_SEMAPHORE_OPEN "Error: semaphore open\n"
# define ERR_SEMAPHORE "Error: semaphore\n"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define VIOLET "\033[0;35m"
# define MICRO_MIN 60
# define TIME_LESS_MIN "Error: time less than 60ms\n"

typedef enum e_semaphore
{
	PRINT,
	DEAD,
	EAT,
	EAT_COUNT,
	FORK,
	STOP,
	CONTROL,
	THINK,
	SLEEP
}					t_semaphore;


typedef struct s_data
{
	int				num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				num_eat;
	long int		time;
	int				num_eat_done;
	pid_t			*pid;
	int				eat_count_total;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*dead_semaphore;
	sem_t			*eat_semaphore;
	sem_t			*stop;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				forks;
	int				eat_count_philo;
	int             n_eat;
	bool			done_eat;
	long int		last_meal_time;
	struct s_data	*data;
}					t_philo;

// process.c
void				init_processes(t_data *data);
void				clear_memory(t_philo *philo);
// fork.c
void				lock_forks(t_philo *philo);
void				unlock_forks(t_philo *philo);
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
void				print_semaphore_queue(t_philo *philo ,t_semaphore action);

// routines.c
void				routine(t_philo *philo);
void				one_philo_routine(t_data *data, int id);
bool				aux_done_eat(t_philo *philo);

// actions.c
bool				philo_dead(t_philo *philo);
void				*check_die(void *arg);
int					philo_sleep(t_philo *philo);
int					philo_eat(t_philo *philo);
int					philo_think(t_philo *philo);
// wrapped_sem.c
void				action_sem_lock(t_philo *philo, t_semaphore type);
void				action_sem_unlock(t_philo *philo, t_semaphore type);
void				action_sem_wait(t_philo *philo, t_semaphore type);
void				action_sem_init(t_data *data, t_semaphore type);

#endif