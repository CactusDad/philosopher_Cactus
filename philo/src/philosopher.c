/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:30:02 by aboudarg          #+#    #+#             */
/*   Updated: 2022/05/20 02:02:17 by aboudarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int	get_num(t_ph_states *state, char *argv[])
{
	int	i;

	i = 0;
	state->num_of_philos = ft_atoi(argv[0]);
	state->time_to_die = ft_atoi(argv[1]);
	state->time_to_eat = ft_atoi(argv[2]);
	state->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4] != NULL)
		state->numotechphilo_must_eat = ft_atoi(argv[4]);
	if (state->num_of_philos <= 0 || state->time_to_die <= 0
		|| state->time_to_eat <= 0 || state->time_to_sleep <= 0
		|| (argv[4] != NULL && state->numotechphilo_must_eat <= 0))
	{
		printf("Error?\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_ph_states	state;
	t_philo		*philosophers;

	if (argc < 5 || argc > 6 || ft_is_numbers_error(argv + 1, argc - 1))
	{
		printf("Error?\n");
		return (1);
	}
	if (get_num(&state, argv + 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philosophers = malloc(sizeof(t_philo) * state.num_of_philos);
	mutex_init(&state);
	philo_init(philosophers, &state);
	if (die_signal(philosophers))
	{
		usleep(400);
		return (0);
	}
	// wait_thread(philosophers, state.num_of_philos);
	// mutex_destroy(&state);
	return (EXIT_FAILURE);
}
