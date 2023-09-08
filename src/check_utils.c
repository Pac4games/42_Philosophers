/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:04:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/08 12:00:29 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	p;
	int	i;

	p = 1;
	while (av[p])
	{
		i = 0;
		while (av[p][i])
		{
			if (av[p][i] < '0' || av[p][i] > '9')
				return (print_err_ret("one or more invalid arguments"));
			i++;
		}
		if (ft_atoi(av[p]) <= 0 || ft_atoi(av[p]) > INT_MAX)
			return (print_err_ret("one or more invalid arguments"));
		p++;
	}
	return (0);
}

int	check_fork_malloc(t_fork **forks, pthread_mutex_t *mutex)
{
	if (!(*forks) || !mutex)
	{
		if (forks)
			free(forks);
		if (mutex)
			free(mutex);
		return (print_err_ret("failed to allocate memory"));
	}
	return (0);
}

int	check_mutex_malloc(pthread_mutex_t *mt1, pthread_mutex_t *mt2)
{
	if (!mt1 || !mt2)
	{
		if (mt1)
			free(mt1);
		if (mt2)
			free(mt2);
		return (print_err_ret("failed to allocate memory"));
	}
	return (0);
}
