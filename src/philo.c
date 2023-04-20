/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by llion             #+#    #+#             */
/*   Updated: 2023/04/20 14:07:56 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)arg;
	i = get_time() - p->p->begin_time;
	while (!p->p->dead)
	{
		take_fork(arg);
		eating(arg);
		if (p->p->nao_tem_fome)
			break ;
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
	params->dead = 0;
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
	pthread_mutex_init(p->death, NULL);
	while (i < p->n_philos && !p->dead)
	{
		i = 0;
		time = get_time();	
		pthread_mutex_lock(p->death);
		if (time - ph[i]->last_eat > p->time_to_die)
		{
			p->dead = 1;
			//display(ph[i], 5);
		}
		pthread_mutex_unlock(p->death);
		usleep(100);
		if (p->dead)
			return (1);
		i = 0;
		while (p->nb_meals != 0 && i < p->n_philos && ph[i]->times_eaten >= p->nb_meals)
			i++;
		if (i == p->n_philos)
		{
			p->nao_tem_fome = 1;
			return (2);
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
		if (slayer(params, params->philos) == 1)	
		{
			display(params->philos[0], 5);
			break;
		}
		else if (slayer(params, params->philos) == 2)
		{
			display(params->philos[0], 6);
			break ;
		}
	}
	return (0);
}
