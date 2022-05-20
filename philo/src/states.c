/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:38:44 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 20:12:47 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating(t_philo *philo)
{
	if (philo->state->death != 1)
	{
		philo->last_eat = get_time() - philo->state->start_time;
		if (philo->num_eat > 0)
		{
			philo->num_eat--;
		}
		my_sleep(philo->state->time_to_eat, philo);
	}
}

void	sleeping(t_philo *philo)
{
	my_sleep(philo->state->time_to_sleep, philo);
}
