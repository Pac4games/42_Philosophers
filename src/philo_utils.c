/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:36:41 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 12:38:18 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_data_set(t_philo_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		return (0);
	data->fork_status = malloc(sizeof(int) * data->num);
	if (!data->fork_status)
	{
		free(data->forks);
		return (0);
	}
	memset(data->fork_status, 0, data->num * sizeof(int));
	return (1);
}

int	philo_args_set(t_philo_data *data, char **av)
{
	data->num = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		data->hunger = ft_atoi(av[5]);
	else
		data->hunger = -1;
	if (!philo_data_set(data))
		return (0);
	return (1);
}

t_philo	philo_create(t_philo_data *data)
{
	t_philo	philo;

	philo.data = data;
	philo.data->status = THINKING;
	philo.data->time_start = timer_start();
	philo.data->time_last_8 = philo.data->time_start;
	philo.data->fork_num = 0;
	return (philo);
}

void	philo_end(t_philo *philos)
{
	int	p;

	p = 0;
	while (p < philos->data->num)
		pthread_mutex_destroy(&philos->data->forks[p++]);
	free(philos->data->forks);
	pthread_mutex_destroy(&philos->data->death);
	pthread_mutex_destroy(&philos->data->msg);
	free(philos);
}
