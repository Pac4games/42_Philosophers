/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:04:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/06 12:02:16 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(char **av)
{
	int	p;
	int	i;

	if (ft_atoi(av[1]) == 0)
		print_err("invalid number of philosophers");
	p = 1;
	while (av[p])
	{
		i = 0;
		while (av[p][i])
		{
			if (av[p][i] < '0' || av[p][i] > '9')
				print_err("one or more invalid arguments");
			i++;
		}
		p++;
	}
}

void	check_fork_malloc(t_fork **forks, pthread_mutex_t *mutex)
{
	if (!(*forks) || !mutex)
	{
		if (forks)
			free(forks);
		if (mutex)
			free(mutex);
		print_err("failed to allocate memory");
	}
}

void	check_mutex_malloc(pthread_mutex_t *mt1, pthread_mutex_t *mt2)
{
	if (!mt1 || !mt2)
	{
		if (mt1)
			free(mt1);
		if (mt2)
			free(mt2);
		print_err("failed to allocate memory");
	}
}
