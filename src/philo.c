/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/10 17:48:07 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

typedef struct	s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				last_eat;
	int				alive;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	pthread_mutex_t	*eat;
}				t_philo;

void	*eat(void *arg)
{
	printf("timestamp_in_ms X is eating \033[33m[OK]\033[0m\n");
	sleep(1);
	return (arg);
}

int main(int argc, char **argv)
{
	t_params	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_params));
	if (!initialization(philo, argc, argv))
		return (-1);
	while (i++ < 20)
		eat(philo);
	free(philo);
	return (0);
}
