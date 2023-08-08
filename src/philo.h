/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/08 17:41:06 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define HAS_FORK 4
# define DEAD 5
# define FREE 0
# define TAKEN 1

typedef struct s_philo_data
{
	pthread_mutex_t	death;
	pthread_mutex_t	msg;
	pthread_mutex_t	*forks;
	long long		time_start;
	long long		time_last_8;
	int				death_num;
	int				eat_num;
	int				fork_num;
	int				*fork_stts;
	int				num;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				hunger;
	int				stts;
}			t_philo_data;

typedef struct s_philo
{
	t_philo_data	*data;
	pthread_t		th;
	int				id;
}			t_philo;

//main.c
void		*routine(void *arg);
//philo_utils.c
t_philo		philo_create(t_philo_data *data);
void		philo_end(t_philo *philos);
int			philo_start(t_philo *philos);
int			philo_isdead(t_philo *philo);
//fork_utils.c
int			forks_hold(t_philo *philo, int left, int right);
void		forks_drop(t_philo *philo, int left, int right);
//time_utils.c
long long	time_start(void);
long long	get_ctime(t_philo philo);
void		nap_time(t_philo *philo, int time2nap);
void		print_philo_ts(t_philo *philo);
//extra_utils.c
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		print_err(char *msg);

#endif
