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

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			numotephilom_eat;
}	t_philo;

typedef struct s_table
{
	t_philo				*philos;
	int					num_philo;
	pthread_mutex_t		*fork;
	long long			current_time;
	long long			last_time;
}	t_table;

#endif