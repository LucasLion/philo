/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:14:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/20 14:04:09 by llion            ###   ########.fr       */
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
	static struct timeval start;
	struct timeval	t;
	long int		get_time;

	gettimeofday(&t, NULL);
	if (start.tv_sec == 0)
		start = t;
	get_time = (t.tv_sec * 1000 - start.tv_sec * 1000) + (t.tv_usec / 1000 - start.tv_usec / 1000);
	return (get_time);
}

void		t_sleep(long int t)
{
	struct timeval a;
	struct timeval b;

	gettimeofday(&a, NULL);
	gettimeofday(&b, NULL); 
	while (((a.tv_sec - b.tv_sec) * 1000) + ((a.tv_usec - b.tv_usec) / 1000) < t)
	{
		usleep(200);
		gettimeofday(&a, NULL);
	}
}


void	display(t_philo *p, int action)
{
	size_t	i;

	i = get_time();
	if (action == 1)
		printf(B RED"%ld\t"NRM" %d\t"YEL"has taken a " L "fork\n"NRM, i, p->id);
	else if (action == 2)
		printf(B RED"%ld\t"NRM" %d\t"CYN"is " L "eating\n"NRM, i, p->id);
	else if (action == 3)
		printf(B RED "%ld\t"NRM" %d\t" BLU "is " L "thinking\n"NRM, i, p->id);
	else if (action == 4)
		printf(B RED "%ld\t"NRM" %d\t" MAG "is " L "sleeping\n"NRM, i, p->id);
	else if (action == 5)
		printf(B RED "%ld\t"NRM" %d\t" MAG L "died\n"NRM, i, p->id);
	else if (action == 6)
		printf(B GRN "All philos have EATEN\n");
}

