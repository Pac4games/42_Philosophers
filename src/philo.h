/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:50 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/07 11:39:37 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_fork
{
	int				*taken;
	pthread_mutex_t	*mutex;
}			t_fork;

typedef struct s_philo_data
{
	int				num;
	int				hunger;
	int				time2eat;
	int				time2sleep;
	unsigned long	time2die;
	unsigned long	time_start;
}			t_data;

typedef struct s_philo
{
	int				id;
	int				eat_num;
	int				*isdead;
	unsigned long	time_start;
	unsigned long	time_last8;
	t_fork			fork_left;
	t_fork			fork_right;
	pthread_t		th;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*death;
	t_data			*data;
}			t_philo;

//extra_utils.c
int				ft_atoi(char *str);
void			print_err(char *msg);
//init_utils.c
void			init_forks(t_fork **forks, int philo_num);
void			init_philos(t_philo **p, t_data *d, t_fork **f, int *ded);
//check_utils.c
void			check_args(char **av);
void			check_fork_malloc(t_fork **forks, pthread_mutex_t *mutex);
void			check_mutex_malloc(pthread_mutex_t *mt1, pthread_mutex_t *mt2);
//philo_utils.c
void			philo_data_set(t_data *data, char **av);
void			philos_gen(t_philo **phils, t_data *d, t_fork **f, int *ded);
void			print_philo_msg(t_philo *philo, char *msg);
void			*philo_routine(void *arg);
//time_utils.c
unsigned long	philo_set_time(void);
unsigned long	philo_get_time(t_philo *philo);
//stts_utils.c
int				philo_isdead(t_philo *philo);
int				philo_kill(t_philo *philo);
int				philo_sleep(t_philo *philo, unsigned long time2nap);
int				philo_eat(t_philo *philo);
//eat_utils.c
void			philo_get_forks(t_philo *philo);
void			philo_drop_forks(t_philo *philo);

#endif
