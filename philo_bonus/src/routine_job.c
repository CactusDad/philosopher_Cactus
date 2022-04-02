#include "philo_bonus.h"

long long get_time(void)
{
	struct timeval time;
	long long mill_time;

	gettimeofday(&time, NULL);
	mill_time = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (mill_time);
}

int	ft_state(t_philo *philo, int state)
{
	if (philo->state->death != 1)
	{
		if (state == RIGHT_FORK)
			take_fork(philo , 1);
		else if (state == LEFT_FORK)
			take_fork(philo, 0);
		else if (state == EATING)
			eating(philo);
		else if (state == SLEEPING)
			sleeping(philo);
		else if (state == THINKING)
			thinking(philo);

	}
	return (0);
}
void    routine(t_philo *philo)
{
	// // while (1)
	// // {
	
		take_fork(philo, LEFT_FORK);
		take_fork(philo, RIGHT_FORK);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	// // }
	
	// printf("%d==>%lld\n", philo->index, philo->state->start_time);

}	