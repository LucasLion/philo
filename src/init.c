/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:43:33 by llion             #+#    #+#             */
/*   Updated: 2023/04/10 17:37:49 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_play(t_params *philo, int argc, char **argv)
{
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = 0;
	if (argc == 5 || argc == 6)
	{
		philo->number_of_philosophers = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
	}
	else
		return 0;
	return (1);
}

int	initialization(t_params *philo, int argc, char ** argv)
{
	if (!(check_digits(argc, argv)))
	{
		printf("Test failed ! WRONG AGRS\n");
		free(philo);
		return (0);
	}
	if (init_play(philo, argc, argv))
		printf("Program initialized...\n");
	else
	{
		printf("exit program... not good args\n");
		free(philo);
		return (0);
	}
	return (1);
}

