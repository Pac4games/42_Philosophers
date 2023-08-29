/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:16 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/29 10:35:58 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_data_set(t_data *data, char **av)
{
	data->num = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (av[5])
		data->hunger = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	int		p;
	int		death_num;
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
	return (EXIT_SUCCESS);
}
