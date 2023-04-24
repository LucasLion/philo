/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/24 10:59:31 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->p->forks[(p->id - 1)]);
	pthread_mutex_lock(p->p->forks[(p->id) % p->p->n_philos]);
	pthread_mutex_init(p->display, NULL);
	pthread_mutex_lock(p->display);
	display(p, 1);
	display(p, 1);
	pthread_mutex_unlock(p->display);
	return (arg);
}

void	*eating(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->display);
	display(p, 2);
	pthread_mutex_unlock(p->display);
	p->last_eat = get_time();
	t_sleep(p->p->time_to_eat);
	(p->times_eaten)++;
	pthread_mutex_unlock(p->p->forks[(p->id - 1)]);
	pthread_mutex_unlock(p->p->forks[(p->id) % p->p->n_philos]);
	return (arg);
}

void	*thinking(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->display);
	display(p, 3);
	pthread_mutex_unlock(p->display);
	return (arg);
}

void	*sleeping(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(p->display);
	display(p, 4);
	pthread_mutex_unlock(p->display);
	t_sleep(p->p->time_to_eat);
	return (arg);
}
