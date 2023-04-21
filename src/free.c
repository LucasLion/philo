/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:41:08 by llion             #+#    #+#             */
/*   Updated: 2023/04/21 12:30:35 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex_and_free(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->n_philos)
	{
		pthread_join(*p->philos[i]->thread, NULL);
		i++;
	}
	i = 0;
	while (i < p->n_philos)
	{
		pthread_mutex_destroy(p->forks[i]);
		free(p->philos[i]->thread);
		free(p->philos[i]->display);
		free(p->philos[i]);
		free(p->forks[i]);
		i++;
	}
	pthread_mutex_destroy(p->death);
	free(p->forks);
	free(p->death);
	free(p->philos);
	free(p);
}
