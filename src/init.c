/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:43:33 by llion             #+#    #+#             */
/*   Updated: 2023/04/11 14:30:15 by llion            ###   ########.fr       */
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

int	init_play(t_params *params, int argc, char **argv)
{
	if (argc == 6)
		params->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		params->number_of_times_each_philosopher_must_eat = 0;
	if (argc == 5 || argc == 6)
	{
		params->number_of_philosophers = ft_atoi(argv[1]);
		params->time_to_die = ft_atoi(argv[2]);
		params->time_to_eat = ft_atoi(argv[3]);
		params->time_to_sleep = ft_atoi(argv[4]);
	}
	else
		return 0;
	return (1);
}

int	initialization(t_params *params, int argc, char ** argv)
{
	if (!(check_digits(argc, argv)))
	{
		printf("Test failed ! WRONG AGRS\n");
		free(params);
		return (0);
	}
	if (init_play(params, argc, argv))
		printf("Program initialized...\n");
	else
	{
		printf("exit program... not good args\n");
		free(params);
		return (0);
	}
	return (1);
}

