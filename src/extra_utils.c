/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:30:48 by paugonca          #+#    #+#             */
/*   Updated: 2023/07/25 13:24:58 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_err(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_args(char **av)
{
	int	p;
	int	i;

	p = 1;
	while (av[p])
	{
		i = 0;
		while (av[p][i])
			if (!ft_isdigit(av[p][i++]))
				print_err("one or more invalid arguments.");
		p++;
	}
}
