/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:42:09 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 15:21:54 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timer_start(void)
{
	struct timeval	time_start;

	gettimeofday(&time_start, NULL);
	return ((time_start.tv_sec * 1000) + (time_start.tv_usec / 1000));
}

long long	timer_get_ctime(t_philo philo)
{
	struct timeval	tod;
	long long		ctime;

	gettimeofday(&tod, NULL);
	ctime = ((tod.tv_sec * 1000) + (tod.tv_usec / 1000)) - 
		philo.data->time_start;
	return (ctime);
}
