/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/14 13:53:02 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = get_time() - philo->p->begin_time;
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork1\n", i, philo->id);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork2\n", i, philo->id);
	pthread_mutex_unlock(philo->right_fork);
	philo->state = 1;
	return (arg);
}
void	*eating(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = get_time() - philo->p->begin_time;
	printf("%ld %d is eating\n", i, philo->id);
	philo->state = 2;
	return (arg);
}
