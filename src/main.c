/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:16 by paugonca          #+#    #+#             */
/*   Updated: 2023/09/07 12:02:13 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	end_program(t_philo *philos, t_fork *forks, t_data data)
{
	int	p;

	p = -1;
	while (++p < data.num)
	{
		pthread_mutex_destroy(philos[p].fork_right.mutex);
		pthread_mutex_destroy(philos[p].fork_left.mutex);
		pthread_mutex_destroy(forks[p].mutex);
	}
	pthread_mutex_destroy(philos->msg);
	pthread_mutex_destroy(philos->death);
	free(philos->msg);
	free(philos->death);
	free(philos);
	free(forks->taken);
	free(forks->mutex);
	free(forks);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		p;
	int		isdead;
	t_data	data;
	t_fork	*forks;
	t_philo	*philos;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	philo_data_set(&data, av);
	init_forks(&forks, data.num);
	if (!forks)
		print_err("failed to allocate memory for the forks");
	isdead = FALSE;
	init_philos(&philos, &data, &forks, &isdead);
	p = 0;
	while (p < data.num)
		pthread_join(philos[p++].th, NULL);
	return (end_program(philos, forks, data));
}
