/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:16:37 by llion             #+#    #+#             */
/*   Updated: 2023/04/14 13:49:56 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*create_fork()
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t));
	if (fork == NULL)
		return (NULL);
	return (fork);
}

pthread_mutex_t	**create_forks(t_params *params)
{
	pthread_mutex_t	**forks;
	int		i;

	i = 0;
	forks = ft_calloc(params->number_of_philosophers + 1, sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (NULL);
	while (i < params->number_of_philosophers)
	{
		forks[i] = create_fork();
		i++;
	}
	return (forks);
}

t_philo	*create_philo(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->state = 1;
	philo->id = id;
	return (philo);
}

t_philo	**create_philos(int n, int id)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = ft_calloc(n + 1, sizeof(t_philo));
	if (philos == NULL)
		return (NULL);
	while (i < n)
	{
		philos[i] = create_philo(id);
		id++;
		i++;
	}
	philos[i] = 0;
	return (philos);
}

t_table	*create_table(t_params *p)
{
	t_table	*t;
	int	id;
	t = malloc(sizeof(t_table));
	if (t == NULL)
		return (NULL);
	id = 1;
	t->n_philos = p->number_of_philosophers;
	t->philos = create_philos(t->n_philos, id);
	t->forks = create_forks(p);
	return (t);
}

