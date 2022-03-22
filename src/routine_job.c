#include "philosopher.h"

long long get_time(void)
{
	struct timeval time;
	long long mill_time;

	gettimeofday(&time, NULL);
	mill_time = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (mill_time);
}

int min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}

int max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

void    *routine(void *obj)
{
    t_philo *philo;
	
    philo = (t_philo *)obj;
	while(1)
	{
		// printf("id: %d\n",t->id);
		// if ((get_time() - philo->last_eat) > philo->state->time_to_die)
		// {
		// printf("get_time%lld\n", (get_time() - philo->last_eat) - philo->state->start_time);
		// printf("die %lld philo %d time_to_die %d\n", get_time() - philo->state->start_time, philo->id , philo->state->time_to_die);
		// 	exit(2);
		// }
		pthread_mutex_lock(&philo->state->forks[min(philo->id, (philo->id + 1) % philo->state->num_of_philos)]);
		take_fork(philo, 1);
		pthread_mutex_lock(&philo->state->forks[max(philo->id, (philo->id + 1) % philo->state->num_of_philos)]);
		take_fork(philo, 0);
		eating(philo);
		if (philo->state->numotechphilo_must_eat > philo->num_eat)
			philo->num_eat++;
		else
			return (NULL);

		pthread_mutex_unlock(&philo->state->forks[(philo->id + 1) % philo->state->num_of_philos]);
		pthread_mutex_unlock(&philo->state->forks[philo->id]);
		sleeping(philo);
		thinking(philo);
		// exit(2);
	}
    return (NULL);
}