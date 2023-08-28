/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:00:52 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/28 15:51:28 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_fork_malloc(t_fork **forks, pthread_mutex_t *mutex)
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

void	init_forks(t_fork **forks, int philo_num)
{
	int				p;
	t_fork_stts		*forks_stts;
	pthread_mutex_t	*mutex;

	forks_stts = malloc(philo_num * sizeof(t_fork_stts));
	if (!forks_stts)
		print_err("failed to allocate memory");
	p = 0;
	while (p < philo_num)
		forks_stts[p++] = E_FREE;
	(*forks) = malloc(philo_num * sizeof(t_fork));
	mutex = malloc(philo_num * sizeof(pthread_mutex_t));
	check_fork_malloc(forks, mutex);
	p = -1;
	while (++p < philo_num)
	{
		(*forks)[p].stts = &(forks_stts[p]);
		pthread_mutex_init(&((mutex)[p]), NULL);
		(*forks)[p].mutex = &(mutex[p]); 
	}
}

void	init_philos(t_philo **philos, t_data *data, t_fork **forks, int *dead)
{
	int	p;
}
