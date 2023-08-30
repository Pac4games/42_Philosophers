/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:16 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/30 15:15:32 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		p;
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
	init_philos(&philos, &data, &forks);
	p = 0;
	while (p < data.num)
		pthread_join(philos[p].id, NULL);
	return (end_program(philos, forks, data));
}
