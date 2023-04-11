/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2043/24/06 43:43:43 by llion             #+#    #+#             */
/*   Updated: 2023/04/11 16:57:07 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*create_philo(t_params *params, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->state = 1;
	philo->id = id;
	philo->time_to_eat = params->time_to_eat;
	philo->time_to_sleep = params->time_to_sleep;
	philo->time_to_die = params->time_to_die;
	philo->thread = malloc(sizeof(pthread_t));
	pthread_create(philo->thread, NULL, eating, philo);
	pthread_join(*philo->thread, NULL);
	pthread_create(philo->thread, NULL, sleeping, philo);
	pthread_join(*philo->thread, NULL);
	return (philo);
}

t_philo	*create_philos(t_params *params)
{
	t_philo	*philos;
	int		id;

	id = 1;
	philos = malloc(sizeof(t_philo) * params->number_of_philosophers + 1);
	if (philos == NULL)
		return (NULL);
	while (params->number_of_philosophers)
	{
		philos = create_philo(params, id);
		params->number_of_philosophers--;
		id++;
	}
	return (philos);
}

int main(int argc, char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!initialization(params, argc, argv))
		return (-1);
	create_philos(params);
	return (0);
}
