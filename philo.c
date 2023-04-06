/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/06 16:54:28 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

void	thread_action()
{
	for (int i = 1; i <= 10; i++)
		printf("%d ", i);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct timeval	tv;
	pthread_t		thread;	

	thread = NULL;
	gettimeofday(&tv, NULL);
	pthread_create(&thread, NULL, thread_action, NULL);
	return (0);
}
