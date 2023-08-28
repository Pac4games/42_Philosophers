/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:04:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 16:06:07 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
