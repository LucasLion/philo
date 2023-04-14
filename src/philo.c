/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/14 11:57:30 by llion            ###   ########.fr       */
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
			philos[i]->left_fork = forks[i]->id;
			philos[i]->right_fork = forks[0]->id;
		}
		else
		{
			philos[i]->left_fork = forks[i]->id;
			philos[i]->right_fork = forks[i + 1]->id;
		}
		i++;
	}
}

void	*routine(void *arg)
{
	pthread_mutex_t *fork;
	pthread_mutex_t *eat;
	t_philo			*p;


	p = arg;
	fork = malloc(sizeof(pthread_mutex_t));
	eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork, NULL);
	pthread_mutex_init(eat, NULL);
	pthread_mutex_lock(fork);
	take_fork(arg);
	pthread_mutex_unlock(fork);
	pthread_mutex_lock(eat);
	eating(arg);
	pthread_mutex_unlock(eat);
	sleeping(arg);
	return (arg);
}

void	create_threads(t_philo *p, t_params *params)
{
	p->thread = malloc(sizeof(pthread_t));
	p->p = params;
	if (p->thread == NULL)
		return ;
	pthread_create(p->thread, NULL, &routine, p);
}

int main(int argc, char **argv)
{
	t_params		*params;
	t_table			*table;
	struct timeval	t;

	gettimeofday(&t, NULL);
	params = malloc(sizeof(t_params));
	params->time = (t.tv_sec * 1000000) + t.tv_usec;
	if (!initialization(params, argc, argv))
		return (-1);
	table = create_table(params);
	associate_forks(params, table->philos, table->forks);
	int i = 0;
	while (table->philos[i])
	{
		create_threads(table->philos[i], params);
		i++;
	}
	return (0);
}
