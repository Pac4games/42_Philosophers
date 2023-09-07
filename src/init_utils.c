/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:00:52 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/07 12:00:05 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_fork **forks, int num)
{
	int				p;
	int				*forks_taken;
	pthread_mutex_t	*mutex;

	forks_taken = malloc(num * sizeof(int));
	if (!forks_taken)
		print_err("failed to allocate memory");
	(*forks) = malloc(num * sizeof(t_fork));
	mutex = malloc(num * sizeof(pthread_mutex_t));
	check_fork_malloc(forks, mutex);
	p = -1;
	while (++p < num)
	{
		forks_taken[p] = FALSE;
		(*forks)[p].taken = &(forks_taken[p]);
		pthread_mutex_init(&((mutex)[p]), NULL);
		(*forks)[p].mutex = &(mutex[p]); 
	}
}

static void	init_mutex(t_philo **philos, int num)
{
	int				p;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*death;

	msg = malloc(sizeof(pthread_mutex_t));
	death = malloc(sizeof(pthread_mutex_t));
	check_mutex_malloc(msg, death);
	if (pthread_mutex_init(msg, NULL) || pthread_mutex_init(death, NULL))
		print_err("failed to create mutex");
	p = -1;
	while (++p < num)
	{
		(*philos)[p].msg = msg;
		(*philos)[p].death = death;
	}
}

void	init_philos(t_philo **philos, t_data *data, t_fork **forks, int *ded)
{
	int	p;

	philos_gen(philos, data, forks, ded);
	init_mutex(philos, data->num);
	data->time_start = philo_set_time();
	p = -1;
	while (++p < data->num)
	{
		if (pthread_create(&((*philos)[p].th), NULL, philo_routine, \
		(void *)(&(*philos)[p])))
			print_err("failed to create threads");
	}
}
