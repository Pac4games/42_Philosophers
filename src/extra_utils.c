/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:30:48 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/08 17:10:05 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	p;

	if (!s)
		return ;
	p = 0;
	while (s[p])
	{
		write(fd, &s[p], 1);
		p++;
	}
}

int	ft_atoi(const char *str)
{
	int			s;
	long long	n;

	s = 1;
	n = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		s *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		n = (n * 10) + (s * (*str - '0'));
		str++;
		if (n > 2147483647)
			return (-1);
		if (n < -2147483648)
			return (0);
	}
	return (n);
}

void	print_err(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
