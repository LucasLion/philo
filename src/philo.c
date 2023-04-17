/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/17 16:21:09 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo		*p;
	size_t		i;

	p = (t_philo *)arg;
	i = get_time() - p->p->begin_time;
	while (!p->is_dead)
	{
		take_fork(arg);
		eating(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (arg);
}

int	create_threads(t_philo *p, t_p *params)
{
	p->p = params;
	p->thread = malloc(sizeof(pthread_t));
	p->display = malloc(sizeof(pthread_mutex_t));
	if (p->thread == NULL)
		return (-1);
	if (pthread_create(p->thread, NULL, &routine, p) != 0)
		return (-2);
	usleep(10);
	return (0);
}

int main(int argc, char **argv)
{
	t_p		*params;
	int i;

	i = 0;
	params = init_params(argc, argv);
	if (params == NULL)
		return (-1);
	while (params->philos[i])
	{
		if (create_threads(params->philos[i], params) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (params->philos[i])
	{
		if (pthread_detach(*params->philos[i]->thread) != 0)
			return (-1);
		i++;
	}
	return (0);
}
