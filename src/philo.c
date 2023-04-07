/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/07 08:55:58 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*thread_action(void *arg)
{
	pthread_mutex_t	mutex;
	(void)arg;
	for (int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex);
		printf("\n");
		pthread_exit(EXIT_SUCCESS);
		for (int j = 0; j < 10; j++)
		{
			pthread_mutex_lock(&mutex);
			printf("%d ", j);
			pthread_exit(EXIT_SUCCESS);
		}
	}
	pthread_mutex_unlock(&mutex);
	return (arg);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct timeval	tv;
	pthread_mutex_t	mutex;
	pthread_t		thread;

	gettimeofday(&tv, NULL);
	printf("avant\n");
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread, NULL, thread_action, NULL);
	pthread_mutex_destroy(&mutex);
	printf("apres\n");
	printf("Time: %ld\n", tv.tv_sec);
	return (0);
}
