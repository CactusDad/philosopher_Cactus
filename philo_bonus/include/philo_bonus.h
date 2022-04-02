/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:29:50 by aboudarg          #+#    #+#             */
/*   Updated: 2022/03/15 22:36:24 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include<stdio.h>
# include<unistd.h>
#include <semaphore.h>

#define RIGHT_FORK 1
#define LEFT_FORK 0
#define EATING 2
#define SLEEPING 3
#define THINKING 4

typedef struct s_ph_states
{
  int   num_of_philos;
  int   time_to_die;
  int   time_to_eat;
  int   time_to_sleep;
  int   numotechphilo_must_eat;
  long long start_time;
  sem_t *forks;
  pthread_mutex_t  print_lock;
  pthread_mutex_t *locks;
  int   death;
}   t_ph_states;

typedef struct s_philo
{
  int index;
  pid_t pid;
  t_ph_states *state;
  long long last_eat;
  int num_eat;

} t_philo;

int     ft_is_numbers_error(char **numbers, int size);
int     ft_isdigit(int c);
void    ft_putstr(char *str);
int     ft_atoi(const char *str);
 /*------------------methods of process----------------*/
 void    init_semaphore(t_philo *philo);
 void    wait_child(t_philo *philo);
 void    init_childs(t_philo philo);
 void    routine(t_philo *philo);
 /*-------------------philosophers state--------------------*/
 long long get_time(void);
 void eating(t_philo *philo);
 void thinking(t_philo *philo);
 void sleeping(t_philo *philo);
 void	take_fork(t_philo *philo, int state);

#endif