#include "philosopher.h"

void philo_init(t_philo *philosophers, t_ph_states *states)
{
	int i;

	i = 0;
	while (i < states->num_of_philos)
	{
		
        philosophers[i].state = states;
		philosophers[i].id = i;
		philosophers[i].num_eat = 0;
		if (i == 0)
			states->start_time = get_time();
		philosophers[i].last_eat = -1; 
		if (pthread_create(&philosophers[i].philo, NULL, routine, &philosophers[i]) != 0)
		{
			printf("Failed to create thread\n");
			break;
		}
		if (i % 2 == 0)
			usleep(50);
		// printf("hey%d\n",table->philos[i].id);
		i++;
	}
}

void wait_thread(t_philo *philosophers, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(philosophers[i].philo, NULL) != 0)
		{
			printf("Faild to join thread\n");
			break;
		}
		i++;
	}
}

void mutex_init(t_ph_states *states)
{
	int i;

	i = 0;
	states->forks = malloc(sizeof(pthread_mutex_t) * states->num_of_philos);
	while (i < states->num_of_philos)
	{
		pthread_mutex_init(&states->forks[i], NULL);
		i++;
	}
	// pthread_mutes_init(&states->print_lock, NULL);
}

void mutex_destroy(t_ph_states *states)
{
	int i;

	i = 0;
	while (i < states->num_of_philos)
	{
		pthread_mutex_destroy(&states->forks[i]);
		i++;
	}
	// pthread_mutex_destroy(&states->print_lock);
}