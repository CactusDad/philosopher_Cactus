/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:39:06 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/15 20:51:31 by aboudarg         ###   ########.fr       */
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

int	min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}

int	max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	ft_state(t_philo *philo, int state)
{
	if (philo->state->death != 1)
	{
		pthread_mutex_lock(&philo->state->print_lock);
		if (state == RIGHT_FORK)
			take_fork(philo, 1);
		else if (state == LEFT_FORK)
			take_fork(philo, 0);
		else if (state == EATING)
			eating(philo);
		else if (state == SLEEPING)
			sleeping(philo);
		else if (state == THINKING)
			thinking(philo);
		pthread_mutex_unlock(&philo->state->print_lock);
	}
	return (0);
}

void	*routine(void *obj)
{
	t_philo	*philo;

	philo = (t_philo *)obj;
	while (TRUE)
	{
		pthread_mutex_lock(&philo->state->forks[philo->id]);
		ft_state(philo, RIGHT_FORK);
		pthread_mutex_lock(&philo->state->forks[(philo->id + 1)
			% philo->state->num_of_philos]);
		ft_state(philo, LEFT_FORK);
		ft_state(philo, EATING);
		if (philo->num_eat == 0)
		{
			pthread_mutex_unlock(&philo->state->forks[(philo->id + 1)
				% philo->state->num_of_philos]);
			pthread_mutex_unlock(&philo->state->forks[philo->id]);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->state->forks[(philo->id + 1)
			% philo->state->num_of_philos]);
		pthread_mutex_unlock(&philo->state->forks[philo->id]);
		ft_state(philo, SLEEPING);
		ft_state(philo, THINKING);
	}
	return (NULL);
}
