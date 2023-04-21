/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:29:12 by llion             #+#    #+#             */
/*   Updated: 2023/04/21 14:23:52 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define NRM	"\033[0m"
# define RED	"\033[31m"
# define GRN	"\033[32m"
# define YEL	"\033[33m"
# define BLU	"\033[34m"
# define MAG	"\033[35m"
# define CYN	"\033[36m"
# define WHT	"\033[37m"
# define B		"\033[1m"
# define L		"\033[4m"

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long int		last_eat;
	pthread_t		*thread;
	pthread_mutex_t	*display;
	pthread_mutex_t	*meal;
	struct s_params	*p;
}					t_philo;

typedef struct s_params
{
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals;
	int					nao_tem_fome;
	long int			begin_time;
	int					dead;
	t_philo				**philos;
	pthread_mutex_t		**forks;
	pthread_mutex_t		*death;
}				t_p;

t_p			*init_params(int argc, char *argv[]);
void		*take_fork(void *arg);
void		*eating(void *arg);
void		*sleeping(void *arg);
void		*thinking(void *arg);
int			check_digits(int argc, char **argv);
int			init_play(t_p *philo, int argc, char **argv);
int			initialization(t_p *philo, int argc, char **argv);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
long int	get_time(void);
void		t_sleep(long int time);
void		display(t_philo *p, int action);
void		destroy_mutex_and_free(t_p *p);
#endif
