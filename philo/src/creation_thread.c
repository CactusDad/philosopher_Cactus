/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:39:20 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/15 20:52:27 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_init(t_philo *philosophers, t_ph_states *states)
{
	int	i;

	i = 0;
	while (i < states->num_of_philos)
	{
		philosophers[i].state = states;
		philosophers[i].id = i;
		philosophers[i].num_eat = states->numotechphilo_must_eat;
		if (i == 0)
			states->start_time = get_time();
		philosophers[i].last_eat = -1;
		if (pthread_create(&philosophers[i].philo, NULL, routine,
				&philosophers[i]) != 0)
		{
			printf("Failed to create thread\n");
			break ;
		}
		if (i % 2 == 0)
			usleep(50);
		i++;
	}
}

void	wait_thread(t_philo *philosophers, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(philosophers[i].philo, NULL) != 0)
		{
			printf("Faild to join thread\n");
			break ;
		}
		i++;
	}
}

void	mutex_init(t_ph_states *states)
{
	int	i;

	i = 0;
	states->forks = malloc(sizeof(pthread_mutex_t) * states->num_of_philos);
	while (i < states->num_of_philos)
	{
		pthread_mutex_init(&states->forks[i], NULL);
		i++;
	}
}

void	mutex_destroy(t_ph_states *states)
{
	int	i;

	i = 0;
	while (i < states->num_of_philos)
	{
		pthread_mutex_destroy(&states->forks[i]);
		i++;
	}
}
