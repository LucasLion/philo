/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:29:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/11 16:50:58 by llion            ###   ########.fr       */
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
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	pthread_t		*thread;
	pthread_mutex_t	*forks;

}					t_philo;
/* ------------ INIT ------------ */

void	*eating(void *arg);
void	*sleeping(void *arg);
void	*thinking(void *arg);
int		check_digits(int argc, char **argv);
int		init_play(t_params *philo, int argc, char **argv);
int		initialization(t_params *philo, int argc, char ** argv);
int		ft_atoi(const char *str);
 
