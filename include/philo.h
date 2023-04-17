/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:29:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/17 16:02:52 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define B	 "\x1B[1m"
#define L	 "\x1B[4m"

struct s_params;

typedef struct	s_philo
{
	int				id;
	int				state;
	int				times_eaten;
	pthread_t		*thread;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*display;
	struct s_params	*p;

}					t_philo;

typedef struct	s_params
{
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	long int			begin_time;
	int					died;
	t_philo				**philos;
	pthread_mutex_t		**forks;
}				t_p;


t_p			*init_params(int argc, char *argv[]);
void		*take_fork(void *arg);
void		*eating(void *arg);
void		*sleeping(void *arg);
void		*thinking(void *arg);
int			check_digits(int argc, char **argv);
int			init_play(t_p *philo, int argc, char **argv);
int			initialization(t_p *philo, int argc, char ** argv);

void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
long int	get_time();
void		t_sleep(long int time, t_p *p);
void		display(size_t i, t_philo *p, int action); 
