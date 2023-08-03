/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/03 16:20:40 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_data_set(t_philo *philo)
{
	philo->data->forks = malloc(sizeof(pthread_mutex_t) * philo->data->num);
	if (!philo->data->forks)
		return (0);
	philo->data->fork_status = malloc(sizeof(int) * philo->data->num);
	if (!philo->data->fork_status)
	{
		free(philo->data->forks);
		return (0);
	}
	memset(philo->data->fork_status, 0, philo->data->num * sizeof(int));
	return (1);
}

static int	philo_rules_set(t_philo *philo, char **av)
{
	philo->data = malloc(sizeof(t_philo_data));
	if (!philo->data)
		return (0);
	philo->data = malloc(sizeof(t_philo_data));
	if (!philo->data)
	{
		free(philo->data);
		return (0);
	}
	philo->data->num = ft_atoi(av[1]);
	philo->data->time2die = ft_atoi(av[2]);
	philo->data->time2eat = ft_atoi(av[3]);
	philo->data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		philo->data->hunger = ft_atoi(av[5]);
	else
		philo->data->hunger = -1;
	if (!philo_data_set(philo))
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
	res = philo_rules_set(&philo, av);
	if (!res)
	{
		philo_free(&philo);
		print_err("failed to allocate memory.");
	}
	philo_free(&philo);
	return (EXIT_SUCCESS);
}
