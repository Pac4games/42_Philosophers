/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:42:09 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/08 17:11:20 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_start(void)
{
	struct timeval	time_start;

	gettimeofday(&time_start, NULL);
	return ((time_start.tv_sec * 1000) + (time_start.tv_usec / 1000));
}

long long	get_ctime(t_philo philo)
{
	struct timeval	tod;
	long long		ctime;

	gettimeofday(&tod, NULL);
	ctime = ((tod.tv_sec * 1000) + (tod.tv_usec / 1000)) - 
		philo.data->time_start;
	return (ctime);
}

void	print_philo_ts(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->msg));
	if (philo->data->stts == EATING && !philo_isdead(philo))
		printf("%lld %d is eating\n", get_ctime(*philo), philo->id);
	else if (philo->data->stts == SLEEPING && !philo_isdead(philo))
		printf("%lld %d is sleeping\n", get_ctime(*philo), philo->id);
	else if (philo->data->stts == THINKING && !philo_isdead(philo))
		printf("%lld %d is thinking\n", get_ctime(*philo), philo->id);
	else if (philo->data->stts == HAS_FORK && !philo_isdead(philo))
		printf("%lld %d has taken a fork", get_ctime(*philo), philo->id);
	else if (philo->data->stts == DEAD)
		printf("%lld %d died", get_ctime(*philo), philo->id);
	pthread_mutex_unlock(&(philo->data->msg));
}
