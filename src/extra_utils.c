/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:33:10 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/29 11:31:42 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	p;
	int	res;
	int	sign;

	p = 0;
	res = 0;
	sign = 1;
	while (str[p] == ' ' || (str[p] >= '\t' && str[p] <= '\r'))
		p++;
	if (str[p] == '-')
	{
		sign = -1;
		p++;
	}
	else if (str[p] == '+')
		p++;
	while (str[p] >= '0' && str[p] <= '9')
	{
		res = res * 10 + str[p] - 48;
		p++;
	}
	return (res * sign);
}

static void	ft_putstr_fd(char *str, int fd)
{
	int	p;

	p = 0;
	while (str[p])
		write(fd, &str[p++], 1);
}

void	print_err(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
