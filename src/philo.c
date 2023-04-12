/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/12 15:53:28 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_fork	*create_fork(int id)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	fork->state = 1;
	fork->id = id;
	return (fork);
}

t_fork	**create_forks(t_params *params, int id)
{
	t_fork	**forks;
	int		i;

	i = 0;
	forks = ft_calloc(params->number_of_philosophers + 1, sizeof(t_fork));
	if (forks == NULL)
		return (NULL);
	while (i < params->number_of_philosophers)
	{
		forks[i] = create_fork(id);
		id++;
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
	return (philos);
}

t_table	*create_table(t_params *p, t_table *t)
{
	int		id;

	id = 0;
	t->n_philos = p->number_of_philosophers;
	t->philos = create_philos(t->n_philos, id);
	t->forks = create_forks(p, id);
	return (t);
}

void	print_table(t_table *t)
{
	int	i = 0;
	while (t->philos[i])
	{
		printf("id: %d\n", t->philos[i]->id);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_params	*params;
	t_table		*table;

	params = malloc(sizeof(t_params));
	if (!initialization(params, argc, argv))
		return (-1);
	table = malloc(sizeof(table));
	if (table == NULL)
		return (-1);
	create_table(params, table);
	//printf("idd: %d\n", table->philos[0]->id);
	print_table(table);
	return (0);
}
