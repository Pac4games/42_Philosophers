/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:00:52 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/31 16:52:26 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_data_set(t_data *data, char **av)
{
	data->num = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		data->hunger = ft_atoi(av[5]);
	else
		data->hunger = -1;
}

void	init_forks(t_fork **forks, int philo_num)
{
	int				p;
	int				*forks_taken;
	pthread_mutex_t	*mutex;

	forks_taken = malloc(philo_num * sizeof(int));
	if (!forks_taken)
		print_err("failed to allocate memory");
	p = 0;
	while (p < philo_num)
		forks_taken[p++] = FALSE;
	(*forks) = malloc(philo_num * sizeof(t_fork));
	mutex = malloc(philo_num * sizeof(pthread_mutex_t));
	check_fork_malloc(forks, mutex);
	p = -1;
	while (++p < philo_num)
	{
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
		printf("failed to create mutex");
	p = 0;
	while (p < num)
	{
		(*philos)[p].msg = msg;
		(*philos)[p++].death = death;
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
		(void *)&(*philos)[p]))
			print_err("failed to create threads");
	}
}

int	end_program(t_philo *philos, t_fork *forks, t_data data)
{
	int	p;

	p = 0;
	while (p < data.num)
	{
		pthread_mutex_destroy(philos[p].fork_right.mutex);
		pthread_mutex_destroy(philos[p].fork_left.mutex);
		pthread_mutex_destroy(forks[p++].mutex);
	}
	pthread_mutex_destroy(philos->msg);
	pthread_mutex_destroy(philos->death);
	free(philos->msg);
	free(philos->death);
	free(philos);
	free(forks->taken);
	free(forks->mutex);
	free(forks);
	return (EXIT_SUCCESS);
}
