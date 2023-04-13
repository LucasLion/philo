/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/13 02:36:31 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_thread(t_philo *p)
{
	p->thread = malloc(sizeof(pthread_t));
	pthread_create(p->thread, NULL, &eating, p);
	sleep(1);
}

int main(int argc, char **argv)
{
	t_params	*params;
	t_table		*table;

	params = malloc(sizeof(t_params));
	if (!initialization(params, argc, argv))
		return (-1);
	table = create_table(params);
	int i = 0;
	while (table->philos[i])
	{
		create_thread(table->philos[i]);
		i++;
	}
	return (0);
}
