/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:38 by paugonca          #+#    #+#             */
/*   Updated: 2023/08/01 18:01:58 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;
int				mails = 0;

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

static void	*routine()
{
	int	p;

	p = 0;
	while (p < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		p++;
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	pthread_t	th[4];
	int			p;

	if (ac != 5 && ac != 6)
		print_err("invalid number of arguments");
	check_args(av);
	printf("Arguments are valid!\n");
	philo_rules_set(&philo, av);
	pthread_mutex_init(&mutex, NULL);
	p = 0;
	while (p < 4)
	{
		if (pthread_create(&th[p], NULL, &routine, NULL))
			print_err("failed to create thread.");
		printf("Thread %d has started.\n", p);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		if (pthread_join(th[p], NULL))
			print_err("failed to join threads.");
		printf("Thread %d has finished.\n", p);
		p++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (EXIT_SUCCESS);
}
