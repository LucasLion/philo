/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/17 17:13:54 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = (get_time() - philo->p->begin_time) / 1000;
	pthread_mutex_lock(philo->p->forks[(philo->id - 1) % philo->p->n_philos]);
	pthread_mutex_lock(philo->p->forks[(philo->id) % philo->p->n_philos]);
	pthread_mutex_lock(philo->display);
	display(i, philo, 1);
	display(i, philo, 1);
	pthread_mutex_unlock(philo->display);
	return (arg);
}
void	*eating(void *arg)
{
	t_philo *p;
	size_t	i;

	p = (t_philo *)arg;
	i = (get_time() - p->p->begin_time) / 1000;
	pthread_mutex_lock(p->display);
	display(i, p, 2);
	pthread_mutex_unlock(p->display);
	usleep(p->p->time_to_eat * 1000);
	pthread_mutex_unlock(p->p->forks[(p->id - 1) % p->p->n_philos]);
	pthread_mutex_unlock(p->p->forks[(p->id)  % p->p->n_philos]);
	return (arg);
}

void	*thinking(void *arg)
{
	t_philo *p;
	size_t	i;

	p = (t_philo *)arg;
	i = (get_time() - p->p->begin_time) / 1000;
	pthread_mutex_lock(p->display);
	display(i, p, 3);
	pthread_mutex_unlock(p->display);
	usleep(500);
	return (arg);
}

void	*sleeping(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = (get_time() - philo->p->begin_time) / 1000;
	pthread_mutex_lock(philo->display);
	display(i, philo, 4);
	pthread_mutex_unlock(philo->display);
	usleep(philo->p->time_to_sleep * 1000);
	return (arg);
}
