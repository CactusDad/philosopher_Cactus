/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:39:06 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/19 23:41:59 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		mill_time;

	gettimeofday(&time, NULL);
	mill_time = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (mill_time);
}

void	*routine(void *obj)
{
	t_philo	*philo;

	philo = (t_philo *)obj;
	while (philo->state->death != 1)
	{
		if (philo->num_eat == 0)
			return (NULL);
		pthread_mutex_lock(&philo->state->forks[philo->id]);
		messages(philo,"has taken a fork right");
		pthread_mutex_lock(&philo->state->forks[(philo->id + 1)
			% philo->state->num_of_philos]);
		messages(philo, "has taken a fork left");
		messages(philo, "is eating");
		eating(philo);
		pthread_mutex_unlock(&philo->state->forks[philo->id]);
		pthread_mutex_unlock(&philo->state->forks[(philo->id + 1)
			% philo->state->num_of_philos]);
		messages(philo, "is sleeping");
		my_sleep(philo->state->time_to_sleep, philo);
		messages(philo, "is thinking");
	}
	return (NULL);
}
