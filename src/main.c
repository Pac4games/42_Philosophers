/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/09 14:57:11 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_args(char **av)
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

static int	data_set(t_philo_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		return (0);
	data->fork_stts = malloc(sizeof(int) * data->num);
	if (!data->fork_stts)
	{
		free(data->forks);
		return (0);
	}
	memset(data->fork_stts, 0, data->num * sizeof(int));
	return (1);
}

static int	args_set(t_philo_data *data, char **av)
{
	data->num = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		data->hunger = ft_atoi(av[5]);
	else
		data->hunger = -1;
	if (!data_set(data))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_philo_data	data;
	int				p;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	if (!args_set(&data, av))
		print_err("failed to allocate memory");
	philos = malloc(sizeof(t_philo) * data.num);
	if (!philos)
	{
		free(data.forks);
		free(data.fork_stts);
		print_err("failed to allocate memory.");
	}
	p = 0;
	while (p < data.num)
		philos[p++] = philo_create(&data);
	if (!philo_start(philos))
		print_err("failed to initialize threads or mutex's.");
	philo_end(philos);
	return (EXIT_SUCCESS);
}
