/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 16:20:58 by paugonca         ###   ########.fr       */
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
# define AVAILABLE 0
# define TAKEN 1

typedef struct s_philo_data
{
	pthread_mutex_t	death;
	pthread_mutex_t	msg;
	pthread_mutex_t	*forks;
	long long		time_start;
	long long		time_last_8;
	int				death_num;
	int				fork_num;
	int				*fork_status;
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

//ft_utils.c
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
//philo_utils.c
t_philo		philo_create(t_philo_data *data);
void		philo_end(t_philo *philos);
int			philo_start(t_philo *philos);
int			philo_isdead(t_philo *philo);
//routine_utils.c
void		*routine(void *arg);
//time_utils.c
long long	time_start(void);
long long	get_ctime(t_philo philo);
//extra_utils.c
void		print_err(char *msg);
void		check_args(char **av);
void		print_philo_status(t_philo *philo, int stts);

#endif
