#include <stdio.h>
#include "philo_bonus.h"
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
void error_event(void)
{
	printf("Error\n");
	exit(2);
}
void	get_num(t_ph_states *state, char *argv[])
{	
	int i;

	i = 0;
	state->num_of_philos = ft_atoi(argv[0]);
	state->time_to_die = ft_atoi(argv[1]); 
	state->time_to_eat = ft_atoi(argv[2]);
	state->time_to_sleep =  ft_atoi(argv[3]);
	if (argv[4] != NULL)
		state->numotechphilo_must_eat = ft_atoi(argv[4]);
	if (state->num_of_philos <= 0 || state->time_to_die <= 0
		|| state->time_to_eat <= 0 || state->time_to_sleep <= 0
		|| ( argv[4] != NULL && state->numotechphilo_must_eat <= 0))
		error_event();
		
	
}
/*######################threads###########################*/

int main(int argc, char *argv[])
{	
	t_ph_states state;
	t_philo philosophers;
     if (argc < 5 || argc > 6 || ft_is_numbers_error(argv + 1, argc - 1))
        {
			printf("Error.\n");
			exit(1);
		}
	get_num(&state, argv + 1);
	// philosophers = malloc(sizeof(t_philo) * state.num_of_philos);
	philosophers.state = &state;
	init_semaphore(&philosophers);
	init_childs(philosophers);



	
	sem_close (philosophers.state->forks);
	sem_unlink ("Open_Sema");
	wait_child(&philosophers);
	
	return (0);
}
