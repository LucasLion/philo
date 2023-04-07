/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/07 08:29:49 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

	gettimeofday(&tv, NULL);
	printf("Time: %ld\n", tv.tv_sec);
	return (0);
}
