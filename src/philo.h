/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/02 14:42:31 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo_rules
{
	int	num;
	int	time2die;
	int	time2eat;
	int	time2sleep;
	int	hunger;
}			t_philo_rules;

typedef struct s_philo
{
	pthread_t		th;
	pthread_mutex_t	mutex;
}			t_philo;

//ft_utils.c
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
//bonus_utils.c
void	print_err(char *msg);
void	check_args(char **av);
//philo_utils.c
void	philo_start(t_philo_rules rul);

#endif
