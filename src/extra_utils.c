/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:30:48 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 16:46:52 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_err(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	print_philo_status(t_philo *philo, int stts)
{
	pthread_mutex_lock(&(philo->data->msg));
	if (stts == EATING && !philo_isdead(philo))
		printf("%lld %d is eating\n", get_ctime(*philo), philo->id);
	else if (stts == SLEEPING && !philo_isdead(philo))
		printf("%lld %d is sleeping\n", get_ctime(*philo), philo->id);
	else if (stts == THINKING && !philo_isdead(philo))
		printf("%lld %d is thinking\n", get_ctime(*philo), philo->id);
	else if (stts == HAS_FORK && !philo_isdead(philo))
		printf("%lld %d has taken a fork", get_ctime(*philo), philo->id);
	else if (stts == DEAD)
		printf("%lld %d died", get_ctime(*philo), philo->id);
	pthread_mutex_unlock(&(philo->data->msg));
}

void	check_args(char **av)
{
	int	p;
	int	i;

	p = 1;
	while (av[p])
	{
		i = 0;
		while (av[p][i])
		{
			if (av[p][i] <= '0' && av[p][i] >= '9')
				print_err("one or more invalid arguments.");
			i++;
		}
		p++;
	}
}
