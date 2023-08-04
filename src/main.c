/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/04 16:03:27 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_data_set(t_philo_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		return (0);
	data->fork_status = malloc(sizeof(int) * data->num);
	if (!data->fork_status)
	{
		free(data->forks);
		return (0);
	}
	memset(data->fork_status, 0, data->num * sizeof(int));
	return (1);
}

static int	philo_args_set(t_philo_data *data, char **av)
{
	data->num = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		data->hunger = ft_atoi(av[5]);
	else
		data->hunger = -1;
	if (!philo_data_set(data))
		return (0);
	return (1);
}

static t_philo	philo_create(t_philo_data *data)
{
	t_philo	philo;

	philo.status = THINKING;
	philo.data = data;
	philo.time_start = timer_start();
	philo.time_last_8 = philo.time_start;
	return (philo);
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_philo_data	data;
	int				p;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
	if (!philo_args_set(&data, av))
		return (0);
	philos = malloc(sizeof(t_philo) * data.num);
	if (!philos)
	{
		free(data.forks);
		free(data.fork_status);
		return (0);
	}
	p = 0;
	while (p < data.num)
		philos[p++] = philo_create(&data);
	return (EXIT_SUCCESS);
}
