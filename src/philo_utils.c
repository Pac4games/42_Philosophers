/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:03:03 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/02 12:42:47 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;
int				mails = 0;

static void	*routine()
{
	int			p;

	p = 0;
	while (p < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		p++;
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

void	philo_start(t_philo_rules rul)
{
	t_philo	philo[rul.num];
	int		p;

	pthread_mutex_init(&mutex, NULL);
	p = 0;
	while (p < rul.num)
	{
		if (pthread_create(&philo[p].th, NULL, &routine, NULL))
			print_err("failed to create thread.");
		printf("Philosopher %d has awaken.\n", p);
		p++;
	}
	p = 0;
	while (p < rul.num)
	{
		if (pthread_join(philo[p].th, NULL))
			print_err("failed to join thread.");
		printf("Philosopher %d has fallen asleep.\n", p);
		p++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
}
