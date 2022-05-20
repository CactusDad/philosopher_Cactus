/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:39:20 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 20:09:09 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_philo(t_philo *philos, t_ph_states *states, int count)
{
	int	i;

	i = count;
	while (i < states->num_of_philos)
	{
		philos[i].state = states;
		philos[i].id = i;
		philos[i].num_eat = states->numotechphilo_must_eat;
		if (i == 0)
			states->start_time = get_time();
		philos[i].last_eat = 0;
		if (pthread_create(&philos[i].philo, NULL, routine,
				&philos[i]) != 0)
		{
			printf("Failed to create thread\n");
			break ;
		}
		i += 2;
	}
}

void	philo_init(t_philo *philosophers, t_ph_states *states)
{
	create_philo(philosophers, states, 0);
	usleep(120);
	create_philo(philosophers, states, 1);
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
	pthread_mutex_init(&states->print_lock, NULL);
}
