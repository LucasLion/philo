/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/19 18:36:02 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo		*p;
	int			i;

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
	p->p = params; p->thread = malloc(sizeof(pthread_t)); p->display = malloc(sizeof(pthread_mutex_t));
	if (p->thread == NULL)
		return (-1);
	if (pthread_create(p->thread, NULL, &routine, p) != 0)
		return (-2);
	return (0);
}

int	slayer(t_p *p, t_philo **ph)
{
	long int	time;
	int			i;

	i = 0;
	while (i < p->n_philos)
	{
		time = get_time();	
		if (time - ph[i]->last_eat > p->time_to_die)
		{
			ph[i]->is_dead = 1;
			display(ph[i], 5);
			return (1);
		}
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	t_p		*params;
	int		i;

	i = 0;
	get_time();
	params = init_params(argc, argv);
	if (params == NULL)
		return (-1);
	while (params->philos[i])
	{
		if (create_threads(params->philos[i], params) != 0)
			return (-1);
		i++;
		usleep(10);
	}
	i = 0;
	while (params->philos[i])
	{
		if (pthread_detach(*params->philos[i]->thread) != 0)
			return (-1);
		i++;
		usleep(10);
	}
	while (1)
	{
		if (slayer(params, params->philos))	
			break;
	}
	return (0);
}
