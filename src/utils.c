/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:14:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/17 17:12:34 by llion            ###   ########.fr       */
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
		sleep(val);
	}
}

void	display(size_t i, t_philo *p, int action)
{
	if (action == 1)
		printf(B RED"%ld\t"NRM" %d\t"YEL"has taken a " L "fork\n"NRM, i, p->id);
	else if (action == 2)
		printf(B RED"%ld\t"NRM" %d\t"CYN"is " L "eating\n"NRM, i, p->id);
	else if (action == 3)
		printf(B RED "%ld\t"NRM" %d\t" BLU "is " L "thinking\n"NRM, i, p->id);
	else if (action == 4)
		printf(B RED "%ld\t"NRM" %d\t" MAG "is " L "sleeping\n"NRM, i, p->id);
}

