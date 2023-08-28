/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:56:17 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 11:53:12 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	philo_eat(t_philo *philo)
{
	philo->data->stts = EATING;
	print_philo_ts(philo);
	philo->data->time_last_8 = get_ctime(*philo);
	nap_time(philo, philo->data->time2eat);
	forks_drop(philo, philo->id - 1, philo->id % philo->data->num);
	if (philo->data->eat_num > 0)
		philo->data->eat_num--;
}

static void	philo_sleep(t_philo *philo)
{
	philo->data->stts = SLEEPING;
	print_philo_ts(philo);
	nap_time(philo, philo->data->time2sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep((philo->data->time2eat * 1000) / 2);
	while (philo->data->eat_num != 0 && !philo_isdead(philo))
	{
		if (philo->data->stts == THINKING && !philo_isdead(philo))
		{
			if (!forks_hold(philo, philo->id - 1, philo->id % philo->data->num))
				return (0);
			philo_eat(philo);
		}
		else if (philo->data->stts == EATING && !philo_isdead(philo))
			philo_sleep(philo);
		else if (philo->data->stts == SLEEPING && !philo_isdead(philo))
		{
			philo->data->stts = THINKING;
			print_philo_ts(philo);
		}
	}
	return (0);
}
