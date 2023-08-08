/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:52:53 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/08 15:36:29 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork(t_philo *philo, int pos)
{
	pthread_mutex_lock(&(philo->data->forks[pos]));
	if (philo->data->fork_stts[pos] == FREE)
	{
		philo->data->fork_stts[pos] = TAKEN;
		philo->data->fork_num++;
		print_philo_status(philo, HAS_FORK);
	}
	pthread_mutex_unlock(&(philo->data->forks[pos]));
}

int	fork_hold(t_philo *philo, int left, int right)
{
	if (philo->data->num == 1)
	{
		printf("0 %d has taken a fork\n", philo->id);
		usleep(philo->data->time2die * 1000);
		printf("%d %d died\n", philo->data->time2die, philo->id);
		return (0);
	}
	while (philo->data->fork_num < 2)
	{
		if (!philo_isdead(philo))
			get_fork(philo, right);
		if (!philo_isdead(philo))
			get_fork(philo, left);
		if (philo_isdead(philo))
			return (0);
	}
	return (1);
}
