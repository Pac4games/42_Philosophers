/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:38:46 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/08 11:54:22 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_data_set(t_data *data, char **av)
{
	(*data).num = ft_atoi(av[1]);
	(*data).time2die = ft_atoi(av[2]);
	(*data).time2eat = ft_atoi(av[3]);
	(*data).time2sleep = ft_atoi(av[4]);
	if (av[5])
		(*data).hunger = ft_atoi(av[5]);
	else
		(*data).hunger = -1;
}

int	philos_gen(t_philo **philos, t_data *data, t_fork **forks, int *ded)
{
	int	p;

	(*philos) = malloc(data->num * sizeof(t_philo));
	if (!(*philos))
		return (print_err_ret("failed to allocate memory"));
	p = -1;
	while (++p < data->num)
	{
		(*philos)[p].isdead = ded;
		(*philos)[p].eat_num = 0;
		(*philos)[p].id = p + 1;
		(*philos)[p].fork_right = (*forks)[p];
		if (p == 0)
			(*philos)[p].fork_left = (*forks)[data->num - 1];
		else
			(*philos)[p].fork_left = (*forks)[p - 1];
		(*philos)[p].data = data;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	philo->time_last8 = 0;
	if (!((*philo).id % 2))
		usleep(10000);
	while (!philo_kill(philo))
	{
		philo_eat(philo);
		if (philo->data->hunger != -1 && philo->eat_num == philo->data->hunger)
			break ;
		if (!philo_kill(philo))
			print_philo_msg(philo, "is sleeping");
		philo_sleep(philo, (*philo).data->time2sleep);
		if (!philo_kill(philo))
			print_philo_msg(philo, "is thinking");
	}
	return (NULL);
}

void	print_philo_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock((*philo).msg);
	printf("%lu %d %s\n", philo_get_time(philo), philo->id, msg);
	pthread_mutex_unlock((*philo).msg);
}
