/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/02 14:16:13 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_rules_set(t_philo_rules *rul, char **av)
{
	rul->num = ft_atoi(av[1]);
	rul->time2die = ft_atoi(av[2]);
	rul->time2eat = ft_atoi(av[3]);
	rul->time2sleep = ft_atoi(av[4]);
	if (av[5])
		rul->hunger = ft_atoi(av[5]);
	else
		rul->hunger = -1;
}

int	main(int ac, char **av)
{
	t_philo_rules	rul;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
	philo_rules_set(&rul, av);
	philo_start(rul);
	return (EXIT_SUCCESS);
}
