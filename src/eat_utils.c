/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:56:07 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/04 16:58:33 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_taken(t_philo *philo)
{
	if (!philo_isdead(philo))
		print_philo_msg(philo, "has taken a fork");
}

void	philo_get_forks(t_philo *philo)
{
	while (!philo_kill(philo))
	{
		pthread_mutex_lock((*philo).fork_right.mutex);
		if (!((*(*philo).fork_right.taken)))
		{
			*((*philo).fork_right.taken) = TRUE;
			pthread_mutex_unlock((*philo).fork_right.mutex);
			break ;
		}
		pthread_mutex_unlock((*philo).fork_right.mutex);
	}
	print_fork_taken(philo);
	while (!philo_kill(philo))
	{
		pthread_mutex_lock((*philo).fork_left.mutex);
		if (!((*(*philo).fork_left.taken)))
		{
			*((*philo).fork_left.taken) = TRUE;
			pthread_mutex_unlock((*philo).fork_left.mutex);
			break ;
		}
		pthread_mutex_unlock((*philo).fork_left.mutex);
	}
	print_fork_taken(philo);
}

void	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_lock((*philo).fork_right.mutex);
	*((*philo).fork_right.taken) = FALSE;
	pthread_mutex_unlock((*philo).fork_right.mutex);
	pthread_mutex_lock((*philo).fork_left.mutex);
	*((*philo).fork_left.taken) = FALSE;
	pthread_mutex_unlock((*philo).fork_left.mutex);
}
