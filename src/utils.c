/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:14:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/14 17:06:05 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s == 0)
		return (0);
	memset(s, 0, count);
	return (s);
}

long int	get_time()
{
	struct timeval	t;
	long int		get_time;

	gettimeofday(&t, NULL);
	get_time = (t.tv_sec * 1000000) + t.tv_usec;
	return (get_time);
}

void		t_sleep(long int time, t_p *p)
{
	long long	i;
	int			val;

	i = get_time();
	while (!(p->died))
	{
		val = get_time() - i;
		if (i >= time)
			break ;
		usleep(50);
	}
}

