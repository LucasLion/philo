/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:43:33 by llion             #+#    #+#             */
/*   Updated: 2023/04/24 15:07:53 by llion            ###   ########.fr       */
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

int	init_play(t_p *params, int argc, char **argv)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (argc == 6)
		params->nb_meals = ft_atoi(argv[5]);
	else
		params->nb_meals = 0;
	if (argc == 5 || argc == 6)
	{
		params->dead = 0;
		params->nao_tem_fome = 0;
		params->n_philos = ft_atoi(argv[1]);
		if (params->n_philos == 0)
			return (0);
		params->time_to_die = ft_atoi(argv[2]);
		params->time_to_eat = ft_atoi(argv[3]);
		params->time_to_sleep = ft_atoi(argv[4]);
		params->begin_time = get_time();
		params->death = malloc(sizeof(pthread_mutex_t));
	}
	else
		return (0);
	return (1);
}
