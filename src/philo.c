/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:32 by llion             #+#    #+#             */
/*   Updated: 2023/04/08 11:24:30 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <string.h>

#if defined (Win32)
#  include <windows.h>
#  define psleep(sec) Sleep ((sec) * 1000)
#elif defined (Linux)
#  include <unistd.h>
#  define psleep(sec) sleep ((sec))
#endif

#define INITIAL_STOCK 500
#define NB_CLIENTS 40

typedef struct s_store
{
	int	stock;
	pthread_t	thread_store;
	pthread_t	thread_clients[NB_CLIENTS];
}				t_store;

t_store store = 
{
	.stock = INITIAL_STOCK,
};

int	get_random(int max)
{
	double	val;

	val = (double)max * rand();
	val = val / (RAND_MAX + 1.0);
	return ((int) val);
}

void *fn_store(void *p_data)
{
	(void)p_data;
	while (1)
	{
		if (store.stock <= 6)
		{
			store.stock = INITIAL_STOCK;
			printf("Remplissage du stock de %d articles!\n", store.stock);
		}
	}
	return (NULL);
}

void *fn_clients(void *p_data)
{
	int	nb = (long long int)p_data;

	while (1)
	{
		int	val = get_random(20);
		sleep(get_random(1));
		store.stock = store.stock - val;
		printf("Client %d\n prend %d du stock, reste %d en stock !\n", nb, val, store.stock);
	}
	return (NULL);
}

int main(void)
{
	long long int	i = 0;
	int	ret = 0;

	printf("Creation du thread du magasin\n");
	ret = pthread_create(&store.thread_store, NULL, fn_store, NULL);
	if (!ret)
	{
		printf("Creation des threads clients !\n");
		for (i = 0; i < NB_CLIENTS; i++)
		{
			ret = pthread_create(&store.thread_clients[i], NULL, fn_clients, (void *)i);
			if (ret)
				fprintf(stderr, "%s", strerror(ret));
		}
	}
	else
		fprintf(stderr, "%s", strerror(ret));
	for (i = 0; i < NB_CLIENTS; i++)
		pthread_join(store.thread_clients[i], NULL);
	pthread_join(store.thread_store, NULL);
	return EXIT_SUCCESS;
}
