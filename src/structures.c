/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:16:37 by llion             #+#    #+#             */
/*   Updated: 2023/04/19 14:51:10 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	*create_fork()
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork, NULL);
	if (fork == NULL)
		return (NULL);
	return (fork);
}

pthread_mutex_t	**create_forks(t_p *params)
{
	pthread_mutex_t	**forks;
	int		i;

	i = 0;
	forks = ft_calloc(params->n_philos + 1, sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (NULL);
	while (i < params->n_philos)
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
	philo->display = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->display, NULL);
	philo->is_dead = 0;
	philo->last_eat = get_time();
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

t_p	*init_params(int argc, char *argv[])
{
	t_p	*p;
	int	id;

	p = malloc(sizeof(t_p));
	if (p == NULL)
		return (NULL);
	if (!(check_digits(argc, argv)) || !init_play(p, argc, argv))
	{
		printf("exit program... WRONG ARGS\n");
		free(p);
		return (NULL);
	}
	id = 1;
	p->forks = create_forks(p);
	p->philos = create_philos(p->n_philos, id);
	return (p);
}

