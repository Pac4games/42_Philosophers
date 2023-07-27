/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/07/27 15:55:28 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_rules_set(t_philo *philo, char **av)
{
	philo->num = ft_atoi(av[1]);
	philo->time2die = ft_atoi(av[2]);
	philo->time2eat = ft_atoi(av[3]);
	philo->time2sleep = ft_atoi(av[4]);
	if (av[5])
		philo->hunger = ft_atoi(av[5]);
	else
		philo->hunger = -1;
}

int	main(int ac, char **av)
{
	t_philo			philo;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
	philo_rules_set(&philo, av);
	if (philo.num == 0)
		print_err("one or more philophers needed.");
}
