/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/13 13:50:48 by llion            ###   ########.fr       */
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

void	create_threads(t_philo *p)
{
	p->thread = malloc(sizeof(pthread_t));
	if (p->thread == NULL)
		return ;
	pthread_create(p->thread, NULL, &take_fork, p);
	pthread_join(*p->thread, NULL);
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
		create_threads(table->philos[i]);
		i++;
	}
	return (0);
}
