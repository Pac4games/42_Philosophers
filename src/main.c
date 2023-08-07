/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/07 12:40:52 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_philo_data	data;
	int				p;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
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
