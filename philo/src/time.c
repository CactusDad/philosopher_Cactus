/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:06:34 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 20:08:08 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philosopher.h>

size_t	get_current_time(t_philo *philo)
{
	return (get_time() - philo->state->start_time);
}

void	my_sleep(size_t milsec, t_philo *philo)
{	
	long long	start;

	start = get_time();
	while ((philo->state->death != 1) && (start + milsec) > get_time())
		usleep(300);
}
