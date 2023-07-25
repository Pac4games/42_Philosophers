/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:51 by paugonca          #+#    #+#             */
/*   Updated: 2023/07/25 13:20:29 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_philo
{
	int	num;
	int	time2die;
	int	time2eat;
	int	time2sleep;
	int	hunger;
}			t_philo;

//bonus_utils.c
void	print_err(char *msg);
void	check_args(char **av);

#endif
