/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/14 17:06:17 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	associate_forks(t_p *p, t_philo **philos, pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	while (i < p->n_philos)
	{
		if (i == p->n_philos - 1)
		{
			philos[i]->left_fork = forks[i];
			philos[i]->right_fork = forks[0];
		}
		else
		{
			philos[i]->left_fork = forks[i];
			philos[i]->right_fork = forks[i + 1];
		}
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo		*p;
	size_t		i;

	p = (t_philo *)arg;
	i = get_time() - p->p->begin_time;
	take_fork(arg);
	eating(arg);
	printf("%ld %d is sleeping\n", i, p->id);
	return (arg);
}

int	create_threads(t_philo *p, t_p *params)
{
	p->p = params;
	p->thread = malloc(sizeof(pthread_t));
	if (p->thread == NULL)
		return (-1);
	if (pthread_create(p->thread, NULL, &routine, p) != 0)
		return (-2);
	return (0);
}

int main(int argc, char **argv)
{
	t_p		*params;

	if (!initialization(params, argc, argv))
		return (-1);
	params = create_table();
	associate_forks(params, params->philos, params->forks);
	int i = 0;
	while (params->philos[i])
	{
		if (create_threads(params->philos[i], params) != 0)
			return (-1);
		i++;
	}
	return (0);
}
