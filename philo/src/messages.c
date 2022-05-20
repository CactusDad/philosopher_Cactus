/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:05:39 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 20:10:04 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philosopher.h>

void	messages(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->state->print_lock);
	if (philo->state->death != 1)
	{
		printf("%zu ", get_current_time(philo));
		printf("%d %s\n", philo->id + 1, str);
	}
	pthread_mutex_unlock(&philo->state->print_lock);
}
