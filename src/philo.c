/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:05:33 by llion             #+#    #+#             */
/*   Updated: 2023/04/24 11:37:28 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (!p->p->dead)
	{
		take_fork(arg);
		eating(arg);
		if (p->p->nao_tem_fome == 1)
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

	i = -1;
	pthread_mutex_init(p->death, NULL);
	while (++i < p->n_philos && !p->dead)
	{
		i = 0;
		pthread_mutex_lock(p->death);
		time = get_time();
		if (time - ph[i]->last_eat > p->time_to_die)
			p->dead = 1;
		if (p->dead)
			return (1);
		pthread_mutex_unlock(p->death);
		i = 0;
		while (p->nb_meals != 0 && i < p->n_philos
			&& ph[i]->times_eaten >= p->nb_meals)
			i++;
		if (i == p->n_philos)
		{
			p->nao_tem_fome = 1;
			return (2);
		}
		i++;
	}
	return (0);
}

int	create_and_detach(t_p *params)
{
	int	i;

	i = 0;
	while (params->philos[i])
	{
		if (create_threads(params->philos[i], params) != 0)
			return (0);
		i++;
		usleep(50);
	}
	i = 0;
	while (params->philos[i])
	{
		if (pthread_detach(*params->philos[i]->thread) != 0)
			return (0);
		i++;
		usleep(50);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	// TODO segfault quand beaucoup de philosophes
	// TODO il meurt en plein repas -> faire une varialbe (en train de manger ou pas)
	// et check for death seulement quand on ne mange pas
	t_p		*params;
	int	i;

	printf(B GRN "╔═══════════════════════════════════╗\n" NRM);
		printf(B GRN"║ "B GRN"Time\t"NRM" Philo\t"
			YEL"Action\t\t"GRN"    ║\n"NRM);
	printf(B GRN "╠═══════════════════════════════════╣\n" NRM);
	get_time();
	params = init_params(argc, argv);
	if (params == NULL || create_and_detach(params) == 0)
		return (-1);
	while (1)
	{
		i = slayer(params, params->philos);
		if (i == 1)
		{
			usleep(100);
			display(params->philos[0], 5);
			break ;
		}
		else if (i == 2)
		{
			//display(params->philos[0], 6);
			usleep(100);
			break ;
		}
	}
	destroy_mutex_and_free(params);
	return (0);
}
