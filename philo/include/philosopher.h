/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:29:50 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/15 22:04:39 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

# define RIGHT_FORK 1
# define LEFT_FORK 0
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define TRUE 1

typedef struct s_ph_states
{
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					numotechphilo_must_eat;
	long long			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		*locks;
	int					death;
}	t_ph_states;

typedef struct s_philo
{
	int			id;
	pthread_t	philo;
	t_ph_states	*state;
	long long	last_eat;
	int			num_eat;

}	t_philo;

int			ft_is_numbers_error(char **numbers, int size);
int			ft_isdigit(int c);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
/*------------------methods of thread----------------*/
void		philo_init(t_philo *philosophers, t_ph_states *states);
void		wait_thread(t_philo *philosophers, int num);
void		mutex_init(t_ph_states *states);
void		mutex_destroy(t_ph_states *states);
void		*routine(void *obj);
/*-------------------philosophers state--------------------*/
long long	get_time(void);
void		eating(t_philo *philo);
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
void		take_fork(t_philo *philo);
/*--------------------------control-----------------------*/
int			die_signal(t_philo *philo);
#endif
