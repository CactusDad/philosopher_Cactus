/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:55:57 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/19 23:43:03 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	satisfied_examiner(t_philo *philo, int *k)
{
	while (*k < philo->state->num_of_philos)
	{
		if (philo[*k].num_eat)
			break ;
		else if (*k == philo->state->num_of_philos - 1)
			return (0);
		(*k)++;
	}
	return (1);
}

int	die_signal(t_philo *philo)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (TRUE)
	{
		if (satisfied_examiner(philo, &k) == 0)
			return (0);
		if ((get_time() - philo[i].last_eat - philo[i].state->start_time) >= philo[i].state->time_to_die)// 9wadha 3lik ayoub chof kidirliha
		{
			pthread_mutex_lock(&philo->state->print_lock);
			philo[i].state->death = 1;
			printf("%lld %d died\n", ((get_time() - philo[i].state->start_time)
					- philo[i].last_eat), philo[i].id + 1);
			pthread_mutex_unlock(&philo->state->print_lock);
		}
		if (philo[i].state->death == 1)
			return (1);
		i++;
		if (i >= philo[0].state->num_of_philos)
			i = 0;
	}
}
