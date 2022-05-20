/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:38:44 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 01:59:58 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



void	eating(t_philo *philo)
{
	philo->last_eat = get_time() - philo->state->start_time;
	philo->num_eat--;
	my_sleep(philo->state->time_to_eat, philo);
	
}

// void	thinking(t_philo *philo)
// {	
// 	if (philo->state->death)
// 		printf("%lld %d is thinking\n",
// 			(get_time() - philo->state->start_time), philo->id + 1);
// }

void	sleeping(t_philo *philo)
{
	my_sleep(philo->state->time_to_sleep, philo);
}

// void	take_fork(t_philo *philo)
// {
// 	if (philo->state->death != 1)
// 	{
// 		printf("%lld %d has taken a fork\n",
// 			(get_time() - philo->state->start_time), philo->id + 1);
// 	}
// }
