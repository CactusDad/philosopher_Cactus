#include<philosopher.h>

long long get_current_time(t_philo *philo)
{
    return (get_time() - philo->state->start_time);
}
void	my_sleep( long long milsec, t_philo *philo)
{	
	long long	start;

	start = get_time();
	while ((philo->state->death != 1) && (start + milsec) > get_time())
		usleep(300);
}