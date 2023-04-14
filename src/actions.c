/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:34 by llion             #+#    #+#             */
/*   Updated: 2023/04/14 18:04:13 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*take_fork(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = get_time() - philo->p->begin_time;
	printf(B RED"%ld\t"NRM" %d\t"YEL"has taken a " L "fork\n"NRM, i, philo->id);
	printf(B RED"%ld\t"NRM" %d\t"YEL"has taken a " L "fork\n"NRM, i, philo->id);
	philo->state = 1;
	return (arg);
}
void	*eating(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = get_time() - philo->p->begin_time;
	printf(B RED"%ld\t"NRM" %d\t"CYN"is " L "eating\n"NRM, i, philo->id);
	philo->state = 2;
	return (arg);
}

void	*sleeping(void *arg)
{
	t_philo *philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = get_time() - philo->p->begin_time;
	printf(B RED"%ld\t"NRM" %d\t"MAG"is " L "sleeping\n"NRM, i, philo->id);
	philo->state = 2;
	return (arg);
}
