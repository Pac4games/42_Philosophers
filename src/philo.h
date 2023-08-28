/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:50 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 16:06:30 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef enum e_fork_stts
{
	E_TAKEN,
	E_FREE
}			t_fork_stts;

typedef enum e_philo_stts
{
	E_ASLEEP,
	E_DEAD,
	E_EATING,
	E_THINKING,
	E_HAS_FORK
}			t_philo_stts;

typedef struct s_fork
{
	t_fork_stts		*stts;
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
	int				num;
	int				eat_num;
	unsigned long	time_start;
	unsigned long	time_last8;
	int				*stts;
	t_fork			fork_left;
	t_fork			fork_right;
	pthread_t		id;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*death;
	t_data			*data;
}			t_philo;

//extra_utils.c
int		ft_atoi(char *str);
void	print_err(char *msg);
//init_utils.c
void	init_forks(t_fork **forks, int philo_num);
//check_utils.c
void	check_fork_malloc(t_fork **forks, pthread_mutex_t *mutex);
void	check_mutex_malloc(pthread_mutex_t *mt1, pthread_mutex_t *mt2);
//philo_utils.c
void	philos_gen(t_philo **philos, t_data *data, t_fork **forks, int *isdead);

#endif
