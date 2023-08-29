/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stts_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:27:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/29 12:11:49 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_isdead(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (philo->death)
	{
		pthread_mutex_unlock(philo->death);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->death);
	return (FALSE);
}

int	philo_kill(t_philo *philo)
{
	if (philo_isdead(philo))
		return (TRUE);
	if (philo_get_time(philo) - philo->time_last8 >= philo->data->time2die)
	{
		pthread_mutex_lock(philo->death);
		*philo->isdead = TRUE;
		if (*philo->isdead)
			print_philo_msg(philo, "died");
		pthread_mutex_unlock(philo->death);
		return (TRUE);
	}
	return (FALSE);
}

int	philo_sleep(t_philo *philo, unsigned long time2nap)
{
	unsigned long	time_start;
	unsigned long	timer;

	time_start = philo_get_time(philo);
	timer = 0;
	while (!philo_kill(philo) && timer <= time2nap)
	{
		if (philo_isdead(philo))
			return (TRUE);
		usleep(100);
		timer = philo_get_time(philo) - time_start;
	}
	if (timer >= time2nap)
		return (FALSE);
	return (TRUE);
}

int	philo_eat(t_philo *philo)
{
	philo_get_forks(philo);
	if (!philo_isdead(philo))
		print_philo_msg(philo, "is eating");
	philo->eat_num++;
	philo->time_last8 = philo_get_time(philo);
	if (philo_sleep(philo, philo->data->time2eat))
		return (TRUE);
}
