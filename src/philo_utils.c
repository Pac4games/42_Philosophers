/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:38:46 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 16:32:10 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_gen(t_philo **philos, t_data *data, t_fork **forks, int *isdead)
{
	int	p;

	(*philos) = malloc(data->num * sizeof(t_philo));
	if (!(*philos))
		print_err("failed to allocate memory");
	p = 0;
	while (p < data->num)
	{
		(*philos)[p].stts = isdead;
		(*philos)[p].eat_num = 0;
		(*philos)[p].num = p;
		(*philos)[p].fork_right = (*forks)[p];
		if (p == 0)
			(*philos)[p].fork_left = (*forks)[data->num - 1];
		else
			(*philos)[p].fork_left = (*forks)[p - 2];
		(*philos)[p++].data = data;
	}
}

void	philo_routine(void *arg)
{
	t_philo *philo;

	philo = ((t_philo *)arg);
	philo->time_last8 = 0;
	if (!((*philo).num % 2))
		usleep(10000);
	while (!philo_isdead(philo))
	{

	}
}
