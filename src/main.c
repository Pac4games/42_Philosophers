/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/07/25 13:25:18 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
//	t_philo	*philo;

	if (ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
}
