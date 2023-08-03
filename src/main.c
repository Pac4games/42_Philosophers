/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/03 16:30:09 by paugonca         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_philo	philo;
	int		res;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
	philo.data = malloc(sizeof(t_philo_data));
	if (!philo.data)
		return (0);
	res = philo_args_set(philo.data, av);
	if (!res)
	{
		free(philo.data);
		print_err("failed to allocate memory.");
	}
	free(philo.data);
	return (EXIT_SUCCESS);
}
