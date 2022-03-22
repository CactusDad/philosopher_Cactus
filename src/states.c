#include "philosopher.h"
void my_sleep( long long milsec)
{	
	long long start;
	start = get_time();
	while ((start + milsec) > get_time())
		usleep(50);

}

void eating(t_philo *philo)
{

	printf("\033[0;33m%lld %d is eating\n\033[0m", (get_time() - philo->state->start_time), philo->id);
	my_sleep(philo->state->time_to_eat);
	// usleep((philo->state->time_to_eat - 10) * 1000);
	// usleep(10 * 1000);
}

void thinking(t_philo *philo)
{
	printf("\033[0;36m%lld %d is thinking\n\033[0m",(get_time() - philo->state->start_time), philo->id );
}
void sleeping(t_philo *philo)
{

	philo->last_eat = get_time() - philo->state->start_time;
	printf("\033[0;35m%lld %d is sleeping\n\033[0m",(get_time() - philo->state->start_time), philo->id);
	my_sleep(philo->state->time_to_sleep);

}

void	take_fork(t_philo *philo, int state)
{
	if (state)
		printf("\033[0;31m%lld %d has taken a right fork\n\033[0m", (get_time() - philo->state->start_time), philo->id);
	else
		printf("\033[0;32m%lld %d has taken a left fork\n\033[0m", (get_time() - philo->state->start_time), philo->id);

}