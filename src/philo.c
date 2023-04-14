/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/14 12:33:37 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	associate_forks(t_params *p, t_philo **philos, t_fork **forks)
{
	int	i;

	i = 0;
	while (i < p->number_of_philosophers)
	{
		if (i == p->number_of_philosophers - 1)
		{
			philos[i]->left_fork = *forks[i];
			philos[i]->right_fork = *forks[0];
		}
		else
		{
			philos[i]->left_fork = *forks[i];
			philos[i]->right_fork = *forks[i + 1];
		}
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo			*p;

	p = arg;
	take_fork(arg);
	eating(arg);
	sleeping(arg);
	return (arg);
}

int	create_threads(t_philo *p, t_params *params)
{
	p->p = params;
	p->thread = malloc(sizeof(pthread_t));
	p->fork = malloc(sizeof(pthread_mutex_t));
	if (p->thread == NULL)
		return (-1);
	if (pthread_create(p->thread, NULL, &routine, p) != 0)
		return (-2);
	return (0);
}

int main(int argc, char **argv)
{
	t_params		*params;
	t_table			*table;

	params = malloc(sizeof(t_params));
	if (!initialization(params, argc, argv))
		return (-1);
	table = create_table(params);
	associate_forks(params, table->philos, table->forks);
	int i = 0;
	while (table->philos[i])
	{
		if (create_threads(table->philos[i], params) != 0)
			return (-1);
		i++;
	}
	return (0);
}
