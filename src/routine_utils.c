/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:15 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 17:21:04 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep((philo->data->time2eat * 1000) / 2);
	while (philo->data->eat_num != 0 && !philo_isdead(philo))
	{
		if (philo->data->stts == THINKING && !philo_isdead(philo))
		{

		}
	}
	return (0);
}
