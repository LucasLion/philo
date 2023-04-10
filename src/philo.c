/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/10 12:06:43 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*eat(void *arg)
{
	t_philo		*philo;

	philo = arg;
	printf("eating-time: %d\n", philo->time_to_eat);
	return (arg);
}

pthread_t	create_philosopher(void)
{
	pthread_t	philosopher;

	pthread_create(&philosopher, NULL, eat, NULL);
	return (philosopher);
}

int main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!initialization(philo, argc, argv))
		return (-1);
	create_philosopher();	
	free(philo);
	return (0);
}
