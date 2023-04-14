/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/14 11:57:31 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->state = 1;
	printf("%ds philo %d has taken a fork\n", philo->p->time_to_eat, philo->id);
	return (arg);
}
void	*eating(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%ds philo %d is eating\n", philo->p->time_to_eat, philo->id);
	philo->state = 2;
	return (arg);
}

void	*sleeping(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%ds philo %d is sleeping\n", philo->p->time_to_sleep, philo->id);
	philo->state = 3;
	return (arg);
}
