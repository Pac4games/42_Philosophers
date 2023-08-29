/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stts_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:27:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 16:44:45 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_isdead(t_philo *philo)
{
	pthread_mutex_lock((*philo).death);
	if ((*philo).death)
	{
		pthread_mutex_unlock((*philo).death);
		return (TRUE);
	}
	pthread_mutex_unlock((*philo).death);
	return (FALSE);
}

int	philo_kill(t_philo *philo)
{
	if (philo_isdead(philo))
		return (TRUE);
	if (get_cur_time(philo) - (*philo).time_last8 >= (*philo).data->time2die)
}

static void	get_forks(t_philo *philo)
{
	while (!philo_isdead(philo))
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
}

int	philo_eat(t_philo *philo)
{
	
}
