/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/02 12:39:20 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdio.h>
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
	pthread_t	th;
}			t_philo;

//bonus_utils.c
void	print_err(char *msg);
void	check_args(char **av);
//philo_utils.c
void	philo_start(t_philo_rules rul);

#endif
