/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 12:39:48 by paugonca         ###   ########.fr       */
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
	int				status;
}			t_philo_data;

typedef struct s_philo
{
	t_philo_data	*data;
	pthread_t		th;
}			t_philo;

//ft_utils.c
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
//philo_utils.c
void		philo_end(t_philo *philos);
t_philo		philo_create(t_philo_data *data);
int			philo_args_set(t_philo_data *data, char **av);
int			philo_data_set(t_philo_data *data);
//time_utils.c
long long	timer_start(void);
//extra_utils.c
void		print_err(char *msg);
void		check_args(char **av);

#endif
