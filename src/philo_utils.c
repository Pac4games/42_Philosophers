/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:36:41 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/08 17:46:25 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	philo_create(t_philo_data *data)
{
	t_philo	philo;

	philo.data = data;
	philo.data->stts = THINKING;
	philo.data->time_start = time_start();
	philo.data->time_last_8 = philo.data->time_start;
	philo.data->fork_num = 0;
	return (philo);
}

int	philo_start(t_philo *philos)
{
	int	p;

	p = 0;
	if (pthread_mutex_init(&(philos->data->death), NULL) || 
		pthread_mutex_init(&(philos->data->msg), NULL))
		return (0);
	while (p < philos->data->num)
		if (pthread_mutex_init(&(philos->data->forks[p++]), NULL))
			return (0);
	p = 0;
	while (p < philos->data->num)
	{
		philos[p].id = p;
	}
	return (1);
}

int	philo_isdead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->death));
	if (philo->data->death_num != 0)
	{
		pthread_mutex_unlock(&(philo->data->death));
		return (1);
	}
	if (philo->data->time2die < get_ctime(*philo) - philo->data->time_last_8)
	{
		philo->data->death_num++;
		pthread_mutex_unlock(&(philo->data->death));
		philo->data->stts = DEAD;
		print_philo_ts(philo);
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->death));
	return (0);
}

void	philo_eat(t_philo *philo)
{
	philo->data->stts = EATING;
	print_philo_ts(philo);
	philo->data->time_last_8 = get_ctime(*philo);
	nap_time(philo, philo->data->time2eat);
	forks_drop(philo, philo->id - 1, philo->id % philo->data->num);
	if (philo->data->eat_num > 0)
		philo->data->eat_num--;
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
