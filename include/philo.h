/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:29:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/12 16:25:20 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_params
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}				t_params;

typedef struct	s_philo
{
	int				id;
	int				state;
	int				left_fork;
	int				right_fork;
	int				times_eaten;
	pthread_t		*thread;
	//pthread_mutex_t	*forks;

}					t_philo;

typedef struct	s_fork
{
	int				id;
	int				state;
}				t_fork;

typedef struct	s_table
{
	int		n_philos;
	t_philo	**philos;
	t_fork	**forks;
}				t_table;

t_table	*create_table(t_params *p);
void	*eating(void *arg);
void	*sleeping(void *arg);
void	*thinking(void *arg);
int		check_digits(int argc, char **argv);
int		init_play(t_params *philo, int argc, char **argv);
int		initialization(t_params *philo, int argc, char ** argv);

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
