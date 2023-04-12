/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/12 16:30:47 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*eating(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%ds philo %d is eating\n", philo->times_eaten, philo->id);
	sleep(philo->times_eaten);
	philo->state = 1;
	return (arg);
}

void	*sleeping(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%ds philo %d is sleeping\n", philo->times_eaten, philo->id);
	sleep(philo->times_eaten);
	philo->state = 2;
	return (arg);
}

void	*thinking(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("%ds philo %d is thinking\n", philo->times_eaten, philo->id);
	sleep(philo->times_eaten);
	philo->state = 3;
	return (arg);
}
